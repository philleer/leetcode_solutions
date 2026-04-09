class Solution {
public:
    bool check(int row, int col, std::vector<std::string> &path) {
        for (int r = 0; r < row; r++) {
            if (path[r][col] == 'Q') return false;
            if ((col - row + r >= 0 && path[r][col - row + r] == 'Q') || (col + row - r < path.size() && path[r][col + row - r] == 'Q')) return false;
        }

        return true;
    }

    void recursive(int n, std::vector<std::string> &path, std::vector<std::vector<std::string>> &results, int row) {
        if (row == n) {
            results.push_back(path);
            return ;
        }

        for (int c = 0; c < n; c++) {
            if (check(row, c, path)) {
                path[row][c] = 'Q';
                recursive(n, path, results, row + 1);
                path[row][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0 || n == 2 || n == 3) return {};
        if (n == 1) return {{"Q"}};

        std::vector<std::vector<std::string>> results;
        std::vector<std::string> init(n, std::string(n, '.'));
        recursive(n, init, results, 0);

        return results;
    }
};