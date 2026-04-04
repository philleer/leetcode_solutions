class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty() || nums[0] > target) return 0;
        if (nums.back() < target) return nums.size();

        int n = nums.size();
        int res_index = -1;
        // // Solution (1): naive method
        // for (int i = 0; i < n; i++) {
        //     if (target >= nums[i]) {
        //         res_index = i;
        //         break;
        //     }
        // }

        // Solution (2): binary search method
        int left = 0;
        int right = n - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        res_index = left;

        return res_index;
    }
};