class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return (target == nums.back() ? 0 : -1);

        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int mid = 0;
        // 0, 1, 2, 3, 4, 5, 6, 7
        // 1, 2, 3, 4, 5, 6, 7, 0
        // 2, 3, 4, 5, 6, 7, 0, 1
        // 3, 4, 5, 6, 7, 0, 1, 2
        // 4, 5, 6, 7, 0, 1, 2, 3
        // 5, 6, 7, 0, 1, 2, 3, 4
        // 6, 7, 0, 1, 2, 3, 4, 5
        // 7, 0, 1, 2, 3, 4, 5, 6
        bool rotated = true;
        while (left <= right) {
            rotated = nums[left] > nums[right];
            if (rotated) {
                if (target == nums[left]) return left;
                if (target > nums[left]) {
                    --right;
                }
                ++left;
            }
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                if (!rotated)
                    left = mid + 1;
            } else {
                if (rotated) {
                    if (target > nums[left]) {
                        right = mid - 1;
                    } else if (target < nums[left]) {
                        ++left;
                    }
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};