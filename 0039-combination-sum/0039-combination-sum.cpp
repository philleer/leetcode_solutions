class Solution {
public:
    void recursive(std::vector<int> &nums, int start_index, std::vector<std::vector<int>> &results, std::vector<int> &path, int target) {
        if (target == 0) {
            results.push_back(path);
            return ;
        }

        for (int i = start_index; i >= 0; i--) {
            int val = nums[i];
            if (target < val) continue;

            path.push_back(val);
            recursive(nums, i, results, path, target - val);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sz = candidates.size();
        std::sort(candidates.begin(), candidates.end());

        std::vector<int> path;
        std::vector<std::vector<int>> results;
        recursive(candidates, sz - 1, results, path, target);

        return results;
    }
};