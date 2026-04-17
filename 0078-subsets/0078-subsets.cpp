class Solution {
public:
    void recursive(std::vector<int> &nums, std::vector<std::vector<int>> &results, std::vector<int> &path, int start_index) {
        if (!path.empty()) {
            results.push_back(path);
        }

        for (int i = start_index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            recursive(nums, results, path, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return {{}};
        if (nums.size() == 1) return {{}, nums};

        std::vector<std::vector<int>> results = {{}};
        std::vector<int> path;
        recursive(nums, results, path, 0);

        return results;
    }
};