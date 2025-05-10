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
void addLeftMost(TreeNode* node, stack<TreeNode*>& st) {
        // cout << "IN" << endl;
        while(node!=nullptr) {
            st.push(node);
            // cout << "pushed\n";
            node=node->left;
        }
    }
    
    int next(stack<TreeNode*>& st) {
        auto top = st.top(); st.pop();
        
        if (top->right!=nullptr) {
            addLeftMost(top->right, st);
        }
        return top->val;
    }
    
    
    
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        // Your code here
        const int max = max;
        stack<TreeNode*> st1, st2;
        addLeftMost(root1, st1);
        addLeftMost(root2, st2);
        
        vector<int> res;
        
        while(!st1.empty() && !st2.empty()) {
            // cout << first<< " " << second << endl;
            int a = st1.top()->val;
            int b = st2.top()->val;
            
            if (a<=b) {
                res.push_back(a);
                next(st1);
            } else {
                res.push_back(b);
                next(st2);
            }
        }
        
        while (!st1.empty()) {
            res.push_back(next(st1));
        }
        
        while (!st2.empty()) {
            res.push_back(next(st2));
        }
        
        
        return res;
        
    }
    // vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
    // }
};