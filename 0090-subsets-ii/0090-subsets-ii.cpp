class Solution {
public:
    void recursive(const std::vector<int> &nums, std::vector<bool> &used, std::vector<std::vector<int>> &results, std::vector<int> &path, int start_index) {
        if (!path.empty()) {
            results.push_back(path);
        }
        if (start_index >= nums.size()) return ;

        for (int i = start_index; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && !used[i - 1] && nums[i] == nums[i - 1]) continue;

            used[i] = true;
            path.push_back(nums[i]);
            recursive(nums, used, results, path, i + 1);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) return {{}};
        if (nums.size() == 1) return {{}, nums};

        std::sort(nums.begin(), nums.end());
        int sz = nums.size();
        std::vector<bool> used(sz, false);
        std::vector<std::vector<int>> results = {{}};
        std::vector<int> path;
        recursive(nums, used, results, path, 0);

        return results;
    }
};