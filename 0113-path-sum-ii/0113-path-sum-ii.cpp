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
    vector<vector<int>> res;

    void dfs(TreeNode* node, int target, int sum, vector<int>& temp) {
        if (node==nullptr) return;

        if (node->left==nullptr && node->right==nullptr) {
            if (target==sum+node->val) {res.push_back(temp); res.back().push_back(node->val);}
            return;
        }

        temp.push_back(node->val);
        dfs(node->left, target, sum + node->val , temp);
        dfs(node->right, target, sum + node->val , temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        dfs(root, targetSum, 0, temp);

        return res;
    }
};