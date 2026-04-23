class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        if (nums.empty()) return -1;

        int sz = nums.size();
        int min_abs = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                int diff = std::abs(i - start);
                min_abs = std::min(diff, min_abs);
                if (min_abs <= 0) break;
            }
        }

        return min_abs;
    }
};