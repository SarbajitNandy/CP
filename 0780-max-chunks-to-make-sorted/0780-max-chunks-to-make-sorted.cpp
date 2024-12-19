class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunk=0, n= arr.size();

        int mx = -1;
        for(int i=0;i<n;i++) {
            mx = max(mx, arr[i]);
            if (i==mx) {
                chunk++; mx = -1;                           
            }
        }
        return chunk;
    }
};