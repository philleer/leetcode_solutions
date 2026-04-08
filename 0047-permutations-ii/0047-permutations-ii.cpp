class Solution {
public:
    void recursive(std::vector<int> &nums, std::vector<std::vector<int>> &results, std::vector<bool> &used, std::vector<int> &path) {
        if (path.size() == nums.size()) {
            results.push_back(path);
            return ;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && !used[i - 1] && nums[i - 1] == nums[i]) continue;

            path.push_back(nums[i]);
            used[i] = true;
            recursive(nums, results, used, path);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return {{}};
        if (sz == 1) return {nums};

        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> results;
        std::vector<int> path;
        std::vector<bool> used(sz, false);
        recursive(nums, results, used, path);

        return results;
    }
};