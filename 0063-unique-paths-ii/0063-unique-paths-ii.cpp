class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
        for (int r = 0; r < m; r++) {
            if (obstacleGrid[r][0]) break;
            dp[r][0] = 1;
        }
        for (int c = 0; c < n; c++) {
            if (obstacleGrid[0][c]) break;

            dp[0][c] = 1;
        }

        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                if (obstacleGrid[r][c]) continue;

                if (dp[r][c - 1] == -1 && dp[r - 1][c] == -1) continue;
                if (dp[r][c - 1] == -1) {
                    dp[r][c] = dp[r - 1][c];
                } else if (dp[r - 1][c] == -1) {
                    dp[r][c] = dp[r][c - 1];
                } else {
                    dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
                }
            }
        }

        if (dp[m - 1][n - 1] == -1) return 0;

        return dp[m - 1][n - 1];
    }
};