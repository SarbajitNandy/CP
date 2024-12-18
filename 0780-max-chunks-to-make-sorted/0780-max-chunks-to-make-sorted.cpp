class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunk=0, n= arr.size();

        int left = 0,right=0;
        int i = 0, c = 0;
        for(int i=0;i<n;i++) {
            if (!(left<=arr[i] && arr[i]<=right)) {
                if (right - left + 1 == c) {chunk++; c=1;left=i; right = arr[i];}
                else {right = arr[i]; c++;}
            } else c++;
        }

        if (arr[n-1]==n-1 || left!=right) chunk++; 

        return chunk;
    }
};