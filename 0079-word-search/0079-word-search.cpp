class Solution {
public:
    typedef vector<int> vi;

    int dirx[4] = {1,0,-1,0};
    int diry[4] = {0,1,0,-1};

    bool recur(int index, int row, int col, vector<vector<char>> &board, string &word) {
        int n = board.size();
        int m = board[0].size();

        if (index == word.length()) return true;

        char t = board[row][col];
        board[row][col] = '.';


        for(int i=0;i<4;i++) {
            int nr = row + dirx[i];
            int nc = col + diry[i];

            if (nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]==word[index]) {
                if (recur(index+1, nr,nc, board, word)) return true;
            }
        }

        board[row][col]=t;
        
        return false;

    }

    bool exist(vector<vector<char> >& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0;i<n;i++ ) {
            for(int j = 0;j<m;j++) {
                if (word[0]==board[i][j]) {
                    if (recur(1, i,j, board, word)) return true;
                }
            }
        }

        return false;

    }
};