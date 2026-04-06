class Solution {
public:
    void recursive(std::vector<int> &nums, int start_index,
        std::vector<bool> &used,
        std::vector<std::vector<int>> &results,
        std::vector<int> &path, int target) {
        if (target == 0) {
            results.push_back(path);
            return ;
        }

        for (int i = start_index; i >= 0; i--) {
            if ((i < nums.size() - 1) && !used[i + 1] && nums[i] == nums[i + 1]) continue;
            int val = nums[i];
            if (target < val) continue;

            path.push_back(val);
            used[i] = true;
            recursive(nums, i - 1, used, results, path, target - val);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());

        std::vector<int> path;
        std::vector<std::vector<int>> results;
        std::vector<bool> used(candidates.size(), false);
        recursive(candidates, candidates.size() - 1, used, results, path, target);

        return results;
    }
};