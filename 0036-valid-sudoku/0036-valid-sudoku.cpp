class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty() || board.size() != 9 || board[0].size() != 9) return false;
        int cols = board.back().size();
        int rows = board.size();

        // verifing every row
        for (int r = 0; r < rows; r++) {
            std::set<char> cset;
            for (int c = 0; c < cols; c++) {
                char ch = board[r][c];
                if (ch == '.') continue;
                if (cset.find(ch) != cset.end()) return false;
                
                cset.insert(ch);
            }
        }

        // verifing every col
        for (int c = 0; c < cols; c++) {
            std::set<char> cset;
            for (int r = 0; r < rows; r++) {
                char ch = board[r][c];
                if (ch == '.') continue;
                if (cset.find(ch) != cset.end()) return false;
                cset.insert(ch);
            }
        }

        // verifing every sub-board
        for (int r = 0; r < rows / 3; r++) {
            for (int c = 0; c < cols / 3; c++) {
                std::set<char> cset;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char ch = board[r * 3 + i][c * 3 + j];
                        if (ch == '.') continue;
                        if (cset.find(ch) != cset.end()) return false;
                        cset.insert(ch);
                    }
                }
            }
        }

        return true;
    }
};