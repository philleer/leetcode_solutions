class Solution {
public:
    bool check(std::vector<std::vector<char>> &board, int row, int col, char val) {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            if (board[r][col] == val) {
                return false;
            }
        }

        for (int c = 0; c < cols; c++) {
            if (board[row][c] == val) {
                return false;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[(row / 3) * 3 + i][(col / 3) * 3 + j] == val) {
                    return false;
                }
            }
        }

        return true;
    }

    bool recursive(std::vector<std::vector<char>> &board) {
        int rows = board.size();
        int cols = board[0].size();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] != '.') continue;

                for (char i = '1'; i <= '9'; i++) {
                    if (check(board, r, c, i)) {
                        board[r][c] = i;
                        if (recursive(board)) return true;
                        board[r][c] = '.';
                    }
                }
                return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board.size();

        recursive(board);
    }
};