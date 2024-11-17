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
    pair<int,int> recur(TreeNode* root) {
        if (root==nullptr) {
            return {0,0};
        }

        auto left = recur(root->left);
        auto right = recur(root->right);

        pair<int,int> res = {root->val + left.second + right.second, max(left.first, left.second) + max(right.first, right.second)};
 
        return res;
    }
    int rob(TreeNode* root) {
        auto res = recur(root);

        return max(res.first, res.second);
    }
};