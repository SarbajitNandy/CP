class Solution {
public:
    string longestPalindrome(string s) {
        size_t n= s.length();
        
        bool dp[n][n]; memset(dp, 0, sizeof dp);
        // for(int i=0;i<n;i++) dp[i][i]=1;
        int ans[2]={0,0},mx=0;
        int start,end;
        for(int k=0;k<n;k++) {
            for(int i=0;i<n-k;i++) {
                start =i;end=i+k;
                if (start==end){dp[start][end]=1;continue;}
                if (start+1==end && s[start]==s[end]) {dp[start][end]=1; if (mx<end-start+1) {mx=end-start+1; ans[0]=start;ans[1]=end;} }
                else if (end-start>1 && s[start]==s[end] && dp[start+1][end-1]) {dp[start][end]=1; if (mx<end-start+1) {mx=end-start+1; ans[0]=start;ans[1]=end;}}
            }
        }
        
        // string s1 = "";
        // for(int i=ans[0];i<=ans[1];i++)s1+=s[i];
        return s.substr(ans[0],ans[1]-ans[0]+1);
    }
};