class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();

        std::vector<int> dp(n, 0);
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (r == 0 && c == 0) {
                    dp[c] = grid[r][c];
                } else if (r == 0) {
                    dp[c] = dp[c - 1] + grid[r][c];
                } else if (c == 0) {
                    dp[c] = dp[c] + grid[r][c];
                } else {
                    dp[c] = std::min(dp[c], dp[c - 1]) + grid[r][c];
                }
            }
        }

        return dp[n - 1];
    }
};