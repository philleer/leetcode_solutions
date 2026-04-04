class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return std::vector<int>(2, -1);
        if (nums.size() == 1 && target == nums.back()) return std::vector<int>(2, 0);
        if (nums.size() == 1 && target != nums.back()) return std::vector<int>(2, -1);
        if (nums[0] == nums.back() && target != nums[0]) return std::vector<int>(2, -1);

        int n = nums.size();
        std::vector<int> results;
        if (nums[0] == nums.back() && target == nums[0]) return std::vector<int>({0, n - 1});

        int left = 0;
        int right = n - 1;
        int mid = 0;
        int lres = -1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                lres = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;                
            } else {
                right = mid - 1;
            }
        }

        if (lres == -1) return std::vector<int>(2, -1);

        int rres = -1;
        left = (lres == -1 ? 0 : lres);
        right = n - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                rres = mid;
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        results.push_back(lres);
        results.push_back(rres);

        return results;
    }
};