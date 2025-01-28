class Solution {
public:

    bool isValidMove(int row, int col, vector<int>& positions) {
        for(int i=0;i<row;i++) {
            if (abs(i-row)==abs(positions[i]-col) || i == row || positions[i]==col) {
                return false;
            }
        }
        return true;
    }
    void recur(int index, int n, vector<int> &positions, vector<vector<int>>& res) {
        if (index==n) {
            res.push_back(positions);
            return;
        }

        for(int col=0; col<n;col++) {
            if (isValidMove(index, col, positions)) {
                positions[index] = col;
                recur(index+1, n,positions,res);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> positions(n,-1);
        vector<vector<int>> res;

        recur(0,n,positions, res);
        vector<vector<string>> ans;
        for(auto e: res) {
            vector<string> r;
            for(int i=0;i<n;i++) {
                string s="";
                for(int j=0;j<n;j++) {
                    if (e[i]==j) s+='Q';
                    else s+='.';
                }

                r.push_back(s);
            }

            ans.push_back(r);
        }

        return ans;
    }
};