class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) return {};
        if (n == 1) return {{1}};

        int num = 0;
        std::vector<std::vector<int>> results(n, std::vector<int>(n, 0));
        for (int r = 0; r <= (n - 1) / 2; r++) {
            for (int col = r; col <= n - r - 1; col++) {
                results[r][col] = ++num;
            }

            for (int row = r + 1; row < n - r - 1; row++) {
                results[row][n - r - 1] = ++num;
            }

            if (num >= n * n) break;
            for (int col = n - r - 1; col >= r; col--) {
                results[n - r - 1][col] = ++num;
            }

            for (int row = n - r - 2; row > r; row--) {
                results[row][r] = ++num;
            }
        }

        return results;
    }
};