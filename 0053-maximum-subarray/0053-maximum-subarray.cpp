class Solution {
public:
    int recursive(std::vector<int> &nums, int left, int right) {
        if (left == right) return nums[left];

        int mid = left + (right - left) / 2;
        int left_max = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            left_max = std::max(sum, left_max);
        }

        sum = 0;
        int right_max = INT_MIN;
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            right_max = std::max(sum, right_max);
        }

        return std::max(left_max + right_max, std::max(recursive(nums, left, mid), recursive(nums, mid + 1, right)));
    }

    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums.back();

        int sz = nums.size();

        // Solution (1): dynamic programming method, time complexity O(n), space complexity O(n)
        // std::vector<int> dp(sz, INT_MIN);
        // dp[0] = nums[0];
        // int max_sum = nums[0];
        // for (int i = 1; i < sz; i++) {
        //     dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
        //     if (dp[i] > max_sum) {
        //         max_sum = dp[i];
        //     }
        // }

        // return max_sum;

        // Solution (2): divide and conquer method
        return recursive(nums, 0, sz - 1);
    }
};