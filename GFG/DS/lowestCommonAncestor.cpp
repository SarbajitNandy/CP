class Solution
{
    public:
    Node* findLca(Node* root, int n1, int n2, bool &v1, bool &v2) {
        if (root==NULL) return NULL;
        
        if (root->data==n1){
            v1 = true;
            return root;
        }
        
        if (root->data==n2){
            v2 = true;
            return root;
        }
        
        Node* left = findLca(root->left, n1,n2,v1,v2);
        Node* right = findLca(root->right, n1,n2,v1,v2);
        
        if (left && right ) return root;
        return left ? left : right;
    }
    bool find(Node* root,int n) {
        if (root==NULL) return false;
        
        if (root->data==n) return true;
        
        return find(root->left, n) || find(root->right, n);
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       bool v1 = false, v2=false;
      Node* l = findLca(root, n1,n2,v1,v2);
       if (v1&&v2 || v1 && find(l, n2) || v2 && find(l, n1)) return l;
       return NULL;
       
    }
};