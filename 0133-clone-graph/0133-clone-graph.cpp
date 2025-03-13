/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* vis[101];
    Node* cloneGraph(Node* node) {
        if (node==nullptr) return nullptr;
        if (vis[node->val]!=nullptr) return vis[node->val];

        Node* nNode = new Node(node->val);
        vis[node->val] = nNode;

        for(Node* e : node->neighbors) {
            nNode->neighbors.push_back(cloneGraph(e));
        }

        return nNode;
    }
};