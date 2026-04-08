class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()) return ;

        int row = matrix.size();
        int col = matrix[0].size();
        if (row != col || row == 1) return ;

        for (int r = 0; r < row; r++) {
            for (int c = r; c < col; c++) {
                std::swap(matrix[r][c], matrix[c][r]);
            }
        }

        for (int r = 0; r < row; r++) {
            std::reverse(matrix[r].begin(), matrix[r].end());
        }
    }
};