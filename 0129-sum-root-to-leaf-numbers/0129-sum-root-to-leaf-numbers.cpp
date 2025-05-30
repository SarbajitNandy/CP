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
    int sum = 0;

    void dfs(TreeNode* root, int num) {
        if (root==nullptr) {
            sum += num;
            return;
        }

        int val = num*10 + root->val;

        if (!root->left  && !root->right) {
            sum += val; return;
        }

        if(root->left) dfs(root->left, val);
        if (root->right) dfs(root->right, val);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);

        return sum;
    }
};