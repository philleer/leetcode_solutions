class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return true;

        if (nums.size() == 1) return true;

        int sz = nums.size();
        std::vector<int> dp(sz, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < sz - 1; i++) {
            if (nums[i] <= 0 || dp[i] == INT_MAX) continue;
            for (int j = i + 1; (j < sz) && (j <= i + nums[i]); j++) {
                dp[j] = std::min(dp[j], dp[i] + 1);
            }
        }

        return dp[sz - 1] != INT_MAX;
    }
};