class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        if (nums.empty() || nums.size() < 2) return -1;

        int sz = nums.size();
        int min_dist = INT_MAX;
        std::unordered_map<int, std::vector<int>> umap;
        for (int i = 0; i < sz; i++) {
            int num = nums[i];

            if (umap.find(nums[i]) != umap.end()) {
                std::vector<int> index = umap[nums[i]];
                for (int j = 0; j < index.size(); j++) {
                    int dist = std::abs(index[j] - i);
                    if (dist < min_dist) {
                        min_dist = dist;
                        if (min_dist == 1) return min_dist;
                    }
                }
            }

            int mirror_num = 0;
            while (num) {
                mirror_num = mirror_num * 10 + num % 10;
                num /= 10;
            }
            umap[mirror_num].push_back(i);
        }

        if (min_dist == INT_MAX) return -1;

        return min_dist;
    }
};