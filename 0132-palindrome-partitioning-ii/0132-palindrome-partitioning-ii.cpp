class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<int> res(n+1,2001);
        res[0]=0;
        
        for(int i=0;i<n;i++) dp[i][i]=1;
        
        for(int k=1;k<n;k++) {
            for(int start = 0; start<n-k;start++) {
                int end = start + k;
                
                if (start+1==end && s[start]==s[end]) {
                    dp[start][end] = 1;
                }
                
                if (end-start>1 && s[start]==s[end] && dp[start+1][end-1]==1) {
                    dp[start][end]=1;
                }
            }
        }
        
        
        for(int part=1;part<=n;part++) {
            for(int j=0;j<part;j++) {
                if (dp[j][part-1]==1) {
                    res[part] = min(res[part], res[j]+1);
                }
            }
        }
        
        
        return res[n]-1;
    }
};