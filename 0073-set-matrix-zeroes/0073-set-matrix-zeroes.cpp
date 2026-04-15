class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || (matrix.size() == 1 && matrix[0].size() == 1)) return ;

        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> zeros(cols, -1);
        bool zero_row = false;
        for (int r = 0; r < rows; r++) {
            zero_row = false;
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == 0) {
                    zero_row = true;
                    zeros[c] = 1;
                } else if (r > 0 && zeros[c] == 1) {
                    matrix[r][c] = 0;
                }
            }

            for (int c = 0; zero_row && c < cols; c++) {
                matrix[r][c] = 0;
            }
        }

        for (int r = 0; r < rows - 1; r++){
            for (int c = 0; c < cols; c++) {
                if (zeros[c] == 1) {
                    matrix[r][c] = 0;
                }
            }
        }
    }
};