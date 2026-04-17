class Solution {
public:
    void recursive(int n, int k, std::vector<std::vector<int>> &results, std::vector<int> &path, std::vector<bool> &used, int start_index) {
        if (path.size() == k) {
            results.push_back(path);
            return ;
        }

        for (int i = start_index; i <= n; i++) {
            if (used[i - 1]) continue;

            path.push_back(i);
            used[i - 1] = true;
            recursive(n, k, results, path, used, i + 1);
            used[i - 1] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0) return {{}};
        if (n == 1 && k == 1) return {{1}};
        
        std::vector<std::vector<int>> results;
        std::vector<int> path;
        std::vector<bool> used(n, false);
        recursive(n, k, results, path, used, 1);

        return results;
    }
};