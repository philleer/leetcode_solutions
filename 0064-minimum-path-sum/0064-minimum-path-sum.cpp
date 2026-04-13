class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int sum = 0;
        if (m == 1) {
            for (int c = 0; c < grid[0].size(); c++) sum += grid[0][c];
            return sum;
        }

        int n = grid[0].size();
        if (n == 1) {
            sum = 0;
            for (int r = 0; r < m; r++) sum += grid[r][0];
            return sum;
        }
        
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, INT_MAX));
        sum = 0;
        for (int r = 0; r < m; r++) {
            sum += grid[r][0];
            dp[r][0] = std::min(sum, dp[r][0]);
        }
        sum = 0;
        for (int c = 0; c < n; c++) {
            sum += grid[0][c];
            dp[0][c] = std::min(sum, dp[0][c]);
        }

        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                dp[r][c] = std::min(dp[r][c - 1], dp[r - 1][c]) + grid[r][c];
            }
        }

        return dp[m - 1][n - 1];
    }
};