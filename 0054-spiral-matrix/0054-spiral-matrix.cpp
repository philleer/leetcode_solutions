class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        if (matrix.size() == 1) return {matrix.back()};
        
        std::vector<int> results;
        if (matrix[0].size() == 1) {
            for (int i = 0; i < matrix.size(); i++) {
                results.push_back(matrix[i].back());
            }
            return results;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int start_row = 0; start_row <= (rows - 1) / 2; start_row++) {
            for (int c = start_row; c <= cols - start_row - 1; c++) {
                results.push_back(matrix[start_row][c]);
            }

            for (int r = start_row + 1; r < rows - start_row - 1; r++) {
                if (cols >= (2 * start_row + 1)) {
                    results.push_back(matrix[r][cols - start_row - 1]);
                }
            }

            for (int c = cols - start_row - 1; c >= start_row; c--) {
                if (rows > 2 * start_row + 1) {
                    results.push_back(matrix[rows - start_row - 1][c]);
                }
            }

            if ((2 * start_row + 1) == cols) break;
            for (int r = rows - start_row - 2; r > start_row; r--) {
                results.push_back(matrix[r][start_row]);
            }

            if (results.size() == rows * cols) break;
        }

        return results;
    }
};