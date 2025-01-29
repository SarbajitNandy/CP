class Solution {
public:
    bool recur(int row, int col, vector<vector<char>>& board) {
        if (col==9) {
            row++;col=0;
        }

        if (row==9) return true;
        
        if (board[row][col]=='.') {
            for(int i=1;i<=9;i++) {
                if (isSafe(board, i+48, row, col)) {
                    board[row][col]=i + 48;
                    if (recur(row, col+1, board)) return true;
                    board[row][col]='.';
                }
            }
            return false;
        } else {
            return recur(row, col+1, board);
        }
    }

    bool isSafe(vector<vector<char>>& board, char num, int row, int col) {
        for(int c=0;c<9;c++) {
            if (board[row][c]==num) return false;
        }

        for(int r=0;r<9;r++) {
            if (board[r][col]==num) return false;
        }

        int sr = row/3 * 3;
        int sc = col/3 * 3;

        for(int r=0;r<3;r++) {
            for(int c=0;c<3;c++) {
                if (board[sr+r][sc+c]==num) return false;
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        recur(0,0,board); 
    }
};