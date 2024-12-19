class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> suffix(n,0), prefix(n,0);
        suffix[n-1]=arr[n-1];
        prefix[0]=arr[0];

        for(int i=n-2;i>=0;i--) {
            suffix[i]= min(arr[i+1],suffix[i+1]);
        }
        
        for(int i=1;i<n;i++) {
            prefix[i]= max(arr[i-1],prefix[i-1]);
        }
        
        int cnt = 0;

        for(int i=0;i<n;i++) {
            if ((arr[i]<=suffix[i] && prefix[i]<=suffix[i]) || i==n-1) cnt++;
        }

        return cnt;
    }
};