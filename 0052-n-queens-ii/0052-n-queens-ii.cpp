class Solution {
public:
    
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int r = row;
        int c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }
        r = row;
        c = col;
        while (c >= 0) {
            if (board[r][c] == 'Q') return false;
            c--;
        }
        r = row;
        c = col;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r++;
            c--;
        }
        return true;
    }
    int count = 0;
    void solve(int col, vector<string> &board, int n){
        if(col == n){
            count++;
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';

                solve(col + 1, board, n);

                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        count = 0;
        vector<string> board(n, string(n, '.'));
        solve(0, board, n);

        return count;
    }
};