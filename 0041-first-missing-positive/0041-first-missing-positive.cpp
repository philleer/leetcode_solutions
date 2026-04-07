class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 1) return (nums.back() == 1) ? 2 : 1;

        // // Solution (1): naive method, time complexity O(n) ~ O(n^2), space complexity O(n)
        // // Cannot pass last testcase (chaos order)
        // int missing = 1;
        // int min_pos = INT_MAX;
        // for (int i = 0; i < sz; i++) {
        //     if (nums[i] < missing) continue;
        //     min_pos = (nums[i] < min_pos ? nums[i] : min_pos);
        //     if (min_pos == 1) break;
        // }

        // if (min_pos > 1) return missing;
        // missing += 1;

        // bool ascending_sorted = true;
        // bool decending_sorted = true;
        // for (int i = 1; i < sz; i++) {
        //     if (nums[i - 1] > nums[i]) {
        //         ascending_sorted = false;
        //         break;
        //     }
        // }
        // for (int i = 1; !ascending_sorted && i < sz; i++) {
        //     if (nums[i - 1] < nums[i]) {
        //         decending_sorted = false;
        //         break;
        //     }
        // }
        // if (ascending_sorted) {
        //     for (int & num : nums) {
        //         if (num < missing) continue;

        //         if (num == missing) {
        //             ++missing;
        //         } else {
        //             break;
        //         }
        //     }
        //     return missing;
        // }

        // if (decending_sorted) {
        //     for (int i = sz - 1; i >= 0; i--) {
        //         if (nums[i] < missing) continue;
        //         if (nums[i] == missing) {
        //             ++missing;
        //         } else {
        //             break;
        //         }
        //     }
        //     return missing;
        // }

        // while (true) {
        //     min_pos = INT_MAX;
        //     for (int & num : nums) {
        //         if (num < missing || num > min_pos) continue;

        //         if (num == missing) {
        //             ++missing;
        //         } else if (num > missing) {
        //             min_pos = (num < min_pos ? num : min_pos);
        //         }
        //     }
        //     if (min_pos > missing) break;
        //     if (min_pos == missing) ++missing;

        //     min_pos = INT_MAX;
        //     for (int i = sz - 1; i >= 0; i--) {
        //         int num = nums[i];
        //         if (num < missing || num > min_pos) continue;
        //         if (num == missing) {
        //             ++missing;
        //         } else if (num > missing) {
        //             min_pos = (num < min_pos ? num : min_pos);
        //         }
        //     }
        //     if (min_pos > missing) break;
        //     if (min_pos == missing) ++missing;
        // }

        // Solution (2): hash
        for (int i = 0; i < sz; i++) {
            while (nums[i] > 0 && nums[i] <= sz && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < sz; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return sz + 1;
    }
};