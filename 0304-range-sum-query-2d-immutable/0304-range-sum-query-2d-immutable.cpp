class NumMatrix {
public:

    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        dp = vector<vector<int>>(n,vector<int>(m,0));
        dp[0][0]=matrix[0][0];

        for(int i=1;i<m;i++) {
            dp[0][i]+= dp[0][i-1] + matrix[0][i];
        }
        for(int i=1;i<n;i++) {
            dp[i][0]+= dp[i-1][0] + matrix[i][0];
        }

        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                int a = dp[i-1][j];
                int b = dp[i][j-1];
                int c = dp[i-1][j-1];
                dp[i][j]=matrix[i][j] + a+b-c;

                // cout << dp[i][j] << endl;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2][col2]-(row1 > 0 ? dp[row1-1][col2] : 0)-(col1 > 0 ? dp[row2][col1-1] : 0)+(row1 > 0 && col1 > 0 ? dp[row1-1][col1-1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */