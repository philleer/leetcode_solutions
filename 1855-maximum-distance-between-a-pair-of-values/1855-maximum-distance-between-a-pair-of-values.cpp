class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) return 0;

        int sz1 = nums1.size();
        int sz2 = nums2.size();
        int max_dist = 0;
        for (int i = 0; i < sz1; i++) {
            if (i < sz2 && nums1[i] > nums2[i]) continue;
            if (i < sz2 && nums1[i] <= nums2.back()) {
                max_dist = std::max(sz2 - 1 - i, max_dist);
                continue;
            }
            // for (int j = sz2 - 1; j >= i; j--) {
            //     if (nums1[i] <= nums2[j]) {
            //         max_dist = std::max(j - i, max_dist);
            //         break;
            //     }
            // }

            int low = i;
            int high = sz2 - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (nums2[mid] < nums1[i]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            low = std::min(low, sz2 - 1);
            max_dist = std::max(low - 1 - i, max_dist);
        }

        return max_dist;
    }
};