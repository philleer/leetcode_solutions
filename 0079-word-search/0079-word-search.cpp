class Solution {
public:
    bool recursive(std::vector<std::vector<char>> &board, std::string &word, std::vector<std::vector<bool>> &used, std::string path, int row, int col) {
        if (path.size() == word.size() && path == word) return true;

        int matched_len = path.size();
        int rows = board.size();
        int cols = board[0].size();
        if (row > 0 && !used[row - 1][col] && board[row - 1][col] == word[matched_len]) {
            used[row - 1][col] = true;
            if (recursive(board, word, used, path + board[row - 1][col], row - 1, col)) return true;
            used[row - 1][col] = false;
        }
        if (col < cols - 1 && !used[row][col + 1] && board[row][col + 1] == word[matched_len]) {
            used[row][col + 1] = true;
            if (recursive(board, word, used, path + board[row][col + 1], row, col + 1)) return true;
            used[row][col + 1] = false;
        }
        if (row < rows - 1 && !used[row + 1][col] && board[row + 1][col] == word[matched_len]) {
            used[row + 1][col] = true;
            if (recursive(board, word, used, path + board[row + 1][col], row + 1, col)) return true;
            used[row + 1][col] = false;
        }
        if (col > 0 && !used[row][col - 1] && board[row][col - 1] == word[matched_len]) {
            used[row][col - 1] = true;
            if (recursive(board, word, used, path + board[row][col - 1], row, col - 1)) return true;
            used[row][col - 1] = false;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() && !word.empty()) return false;
        if (word.empty()) return true;

        int rows = board.size();
        int cols = board[0].size();
        if (rows == 1 || cols == 1) {
            std::string str;
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) {
                    str += board[r][c];
                }
            }
            if (str.find(word) != std::string::npos) return true;
            std::reverse(str.begin(), str.end());
            return str.find(word) != std::string::npos;
        }

        std::vector<std::vector<bool>> used(rows, std::vector<bool>(cols, false));
        std::string path;
        int len = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] != word[0]) continue;

                path = std::string(1, word[0]);
                used[r][c] = true;
                if (recursive(board, word, used, path, r, c)) return true;
                used[r][c] = false;
            }
        }

        return false;
    }
};