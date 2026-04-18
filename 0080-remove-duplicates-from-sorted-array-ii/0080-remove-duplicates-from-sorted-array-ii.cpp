class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return -1;
        if (nums.size() <= 2) return nums.size();

        int sz = nums.size();
        int cnt = 0;
        int k = sz;
        for (int i = 1; i < sz; i++) {
            if (nums[i] == nums[i - 1]) {
                ++cnt;
            } else {
                if (cnt) k -= (cnt - 1);
                cnt = 0;
            }
        }
        if (cnt) k -= (cnt - 1);

        cnt = 0;
        for (int i = 1; i < sz;) {
            if (nums[i] == nums[i - 1]) {
                ++cnt;
                i++;
            } else {
                if (cnt) {
                    for (int j = i; j < sz; j++) {
                        nums[j - cnt + 1] = nums[j];
                    }
                    sz -= (cnt - 1);
                    i -= (cnt - 1);
                }
                i++;
                cnt = 0;
            }
        }

        return k;
    }
};