class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,0);
        dp[0]=1;
        int a=0,b=0,c=0;

        for(int i=1;i<n;i++) {
            int mul2 = dp[a]*2;
            int mul3 = dp[b]*3;
            int mul5 = dp[c]*5;
            dp[i]= min({mul2, mul3, mul5});

            if (dp[i]==mul2) a++;
            if (dp[i]==mul3) b++;
            if (dp[i]==mul5) c++;
        }

        return dp[n-1];
    }
};