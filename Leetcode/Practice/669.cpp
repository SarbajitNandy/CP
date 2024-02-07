//669. Trim a Binary Search Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root==NULL) return NULL;
        int val = root->val;
        if (val>=low && val<=high) {
            root->left = trimBST(root->left, low,high);
            root->right = trimBST(root->right, low,high);
            return root;
        } else if (val<low) {
            return trimBST(root->right, low,high);
        } else {
            return trimBST(root->left, low,high);
        }
    }
};


/*
[3,0,4,null,2,null,null,1]

[3,null,null,null,2,null,null,1]
 0   1   2    3   4   5   6   7

left -> 2n+1
right -> 2n+2

*/