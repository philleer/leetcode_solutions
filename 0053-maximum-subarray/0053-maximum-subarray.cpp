class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums.back();

        int max_sum = INT_MIN;
        int sz = nums.size();
        std::vector<int> dp(sz, INT_MIN);
        dp[0] = nums[0];
        for (int i = 1; i < sz; i++) {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > max_sum) {
                max_sum = dp[i];
            }
        }
        max_sum = std::max(dp[0], max_sum);

        return max_sum;
    }
};