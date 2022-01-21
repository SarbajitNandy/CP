class Solution {
public:
    int u_bound(vector<vector<int>> &matrix, int target) {
        int r = matrix.size();
        int left=0,right=r, mid;
        
        while(left!=right) {
            mid=(left+right)>>1;
            if (matrix[mid][0]<=target) {
                left=mid+1;
            } else right=mid;
        }
        
        return left;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int u_idx = u_bound(matrix, target);
        // cout << u_idx << endl;
        if (u_idx==0) return false;
        u_idx--;
        
        return binary_search(matrix[u_idx].begin(),matrix[u_idx].end(), target);
    }
};