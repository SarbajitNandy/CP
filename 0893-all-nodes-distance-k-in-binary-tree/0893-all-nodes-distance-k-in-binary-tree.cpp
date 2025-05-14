/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parents;
    unordered_set<TreeNode*> visited;
    vector<int> res;

    void dfs(TreeNode* target, int count, int k) {
        if (!target || visited.count(target)) return;

        visited.insert(target);
        if (count==k) {res.push_back(target->val); return;}

        dfs(target->left, count+1, k);
        dfs(target->right, count+1, k);
        dfs(parents[target], count+1, k);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> qu;

        parents[root]=nullptr;
        qu.push(root);

        while(!qu.empty()) {
            auto front = qu.front(); qu.pop();

            if (front->left) {
                parents[front->left]=front;
                qu.push(front->left);
            }
            if (front->right) {
                parents[front->right]=front;
                qu.push(front->right);
            }
        }

        dfs(target,0,k);

        return res;

    }
};