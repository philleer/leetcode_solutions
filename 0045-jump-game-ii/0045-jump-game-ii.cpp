class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 1 || nums[0] == 0) return 0;

        std::vector<int> dp(sz, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < sz; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] + j >= i) {
                    dp[i] = std::min(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp.back();
    }
};