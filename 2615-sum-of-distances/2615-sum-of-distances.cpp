class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        if (nums.empty()) return {};

        int sz = nums.size();
        std::unordered_map<int, std::vector<int>> umap;
        for (int i = 0; i < sz; i++) umap[nums[i]].push_back(i);
        if (umap.size() == sz) return std::vector<long long>(sz, 0);

        std::vector<long long> res(sz, 0);
        for (auto it = umap.begin(); it != umap.end(); it++) {
            std::vector<int> vec = it->second;
            if (vec.size() == 1) continue;

            long long vsz = vec.size();
            long long total_sum = vec.back();
            std::vector<long long> sums(vsz, 0);
            sums[vsz - 1] = vec.back();
            for (int i = vsz - 2; i >= 0; i--) {
                total_sum += vec[i];
                sums[i] = sums[i + 1] + vec[i];
            }

            for (int j = 0; j < vsz; j++) {
                long long idx = vec[j];
                res[idx] = vsz * idx - total_sum + 2 * (sums[j] - (vsz - j) * idx);
            }
        }

        return res;
    }
};