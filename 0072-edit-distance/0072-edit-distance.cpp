class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) return word2.length();
        if (word2.empty()) return word1.length();

        int wlen1 = word1.length();
        int wlen2 = word2.length();

        std::vector<std::vector<int>> dp(wlen1 + 1, std::vector<int>(wlen2 + 1, 0));
        for (int i = 0; i <= wlen1; i++) dp[i][0] = i;
        for (int j = 0; j <= wlen2; j++) dp[0][j] = j;

        for (int i = 1; i <= wlen1; i++) {
            for (int j = 1; j <= wlen2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1]) + 1);
                } else {
                    dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }

        return dp[wlen1][wlen2];
    }
};