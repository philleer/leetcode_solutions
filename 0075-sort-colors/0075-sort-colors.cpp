class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty() || nums.size() < 2) return ;

        std::vector<int> cnts(3, 0);
        for (int & num : nums) {
            ++cnts[num];
        }

        int index = 0;
        for (int i = 0; i < 3; i++) {
            while (--cnts[i] >= 0) {
                nums[index++] = i;
            }
        }
    }
};