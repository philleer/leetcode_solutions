class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty() || (nums.size() == 1 && target != nums.back())) return false;
        if (nums.size() == 1 && target == nums.back()) return true;

        // Solution (1) : allocate another vector to save sorted nums
        // int pivot = -1;
        // int sz = nums.size();
        // for (int i = 1; i < sz; i++) {
        //     if (nums[i] < nums[i - 1]) {
        //         pivot = i - 1;
        //         break;
        //     }
        // }
        // std::vector<int> sorted_nums;
        // if (pivot != -1) {
        //     sorted_nums.assign(nums.begin() + pivot + 1, nums.end());
        //     sorted_nums.insert(sorted_nums.end(), nums.begin(), nums.begin() + pivot);
        // } else {
        //     sorted_nums.assign(nums.begin(), nums.end());
        // }

        // // standard binary search
        // int low = 0;
        // int high = sz -1;
        // while (low <= high) {
        //     int mid = low + (high - low) / 2;
        //     if (sorted_nums[mid] == target) return true;

        //     if (sorted_nums[mid] < target) {
        //         low = mid + 1;
        //     } else {
        //         high = mid - 1;
        //     }
        // }

        // return false;

        // Solution (2)
        int sz = nums.size();
        int low = 0;
        int high = sz - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return true;

            // nums[mid] vs nums[low] vs nums[high]
            // (1) nums[low] < nums[high] only increasing part
            //     standard binary search
            // (2) nums[low] >= nums[high] rotated part
            //     nums[mid] > nums[low] // first increasing part
            //     nums[mid] < nums[low] // second increasing part
            //     nums[mid] == nums[low] // ?

            //     nums[mid] > nums[high] // first increasing part
            //     nums[mid] == nums[high] // ?
            //     nums[mid] < nums[high] //second increasing part
            if (nums[low] < nums[high]) {
                if (nums[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if (nums[mid] > nums[low] || nums[mid] > nums[high]) {
                    if (nums[mid] > nums[low]) {
                        if (nums[mid] > target) {
                            if (nums[low] > target) {
                                low = mid + 1;
                            } else if (nums[low] <= target) {
                                high = mid - 1;
                            }
                        } else {
                            low = mid + 1;
                        }
                    } else {
                        if (nums[mid] > target) {
                            if (nums[high] >= target) {
                                low = mid + 1;
                            } else {
                                high = mid - 1;
                            }
                        } else {
                            low = mid + 1;
                        }
                    }
                } else if (nums[mid] < nums[low] || nums[mid] < nums[high]) {
                    if (nums[mid] > target) {
                        high = mid - 1;
                    } else {
                        if (nums[low] > target) {
                            low = mid + 1;
                        } else if (nums[low] <= target) {
                            if (nums[low] == target) return true;

                            high = mid - 1;
                        }
                    }
                } else if (nums[mid] == nums[low] || nums[mid] == nums[high]) {
                    if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
                        ++low;
                    } else if (nums[mid] == nums[low]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
        }

        return false;
    }
};