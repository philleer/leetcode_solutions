class Solution {
public:
    bool check(int row, int col, std::vector<std::string> &path) {
        for (int r = 0; r < row; r++) {
            if (path[r][col] == 'Q') return false;
            if ((col - row + r >= 0 && path[r][col - row + r] == 'Q') ||
                (col + row - r < path.size() && path[r][col + row - r] == 'Q')) return false;
        }

        return true;
    }

    void recursive(int n, std::vector<std::string> &path, int &cnt, int row) {
        if (row == n) {
            ++cnt;
            return ;
        }

        for (int c = 0; c < n; c++) {
            if (check(row, c, path)) {
                path[row][c] = 'Q';
                recursive(n, path, cnt, row + 1);
                path[row][c] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        if (n <= 0 || n == 2 || n == 3) return 0;
        if (n == 1) return 1;

        int cnt_solutions = 0;
        std::vector<std::string> path(n, std::string(n, '.'));
        recursive(n, path, cnt_solutions, 0);

        return cnt_solutions;
    }
};