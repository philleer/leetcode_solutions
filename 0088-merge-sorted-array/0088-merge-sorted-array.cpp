class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) nums1 = nums2;
        if (n == 0) return ;

        int index1 = 0;
        int index2 = 0;
        int index = 0;
        std::vector<int> tmp(nums1);
        while (true) {
            if (tmp[index1] < nums2[index2]) {
                nums1[index++] = tmp[index1++];
            } else {
                nums1[index++] = nums2[index2++];
            }

            if (index > m + n || index1 >= m || index2 >= n) break;
        }

        while (index1 < m) {
            nums1[index++] = tmp[index1++];
        }
        while (index2 < n) {
            nums1[index++] = nums2[index2++];
        }
    }
};