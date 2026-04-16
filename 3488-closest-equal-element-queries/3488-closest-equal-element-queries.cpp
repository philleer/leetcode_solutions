class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        if (nums.empty()) return std::vector<int>(queries.size(), -1);
        if (queries.empty()) return {};

        int nsz = nums.size();
        int qsz = queries.size();
        std::unordered_map<int, std::vector<int>> umap;
        for (int i = 0; i < nsz; i++) {
            umap[nums[i]].push_back(i);
        }

        std::vector<int> res(qsz, -1);
        for (int k = 0; k < qsz; k++) {
            int idx = queries[k];
            if (umap.find(nums[idx]) != umap.end()) {
                std::vector<int> &vec_idx = umap[nums[idx]];
                int vsz = vec_idx.size();
                if (vsz <= 2) {
                    if (vsz == 2) {
                        res[k] = std::min(vec_idx[1] - vec_idx[0], vec_idx[0] + nsz - vec_idx[1]);
                    }
                    continue;
                }

                int dist = -1;
                int min_dist = INT_MAX;

                int low = 0;
                int high = vsz - 1;
                int mid = 0;
                while (low <= high) {
                    mid = low +(high - low) / 2;

                    if (vec_idx[mid] <= idx) {
                        low = mid + 1;
                    } else if (vec_idx[mid] > idx) {
                        high = mid - 1;
                    }
                }
                if (vec_idx[high] == idx) {
                    int dist_prev = std::min(std::abs(idx - vec_idx[(high - 1 + vsz) % vsz]), nsz - std::abs(idx - vec_idx[(high - 1 + vsz) % vsz]));
                    int dist_next = std::min(std::abs(idx - vec_idx[(high + 1) % vsz]), nsz - std::abs(idx - vec_idx[(high + 1) % vsz]));
                    dist = std::min(dist_prev, dist_next);
                } else {
                    int dist_prev = std::min(std::abs(idx - vec_idx[high]), nsz - std::abs(idx - vec_idx[high]));
                    int dist_next = std::min(std::abs(vec_idx[(high + 2) % vsz] - idx), nsz - std::abs(vec_idx[(high + 2) % vsz] - idx));
                    dist = std::min(dist_prev, dist_next);
                }
                res[k] = dist;

                // for (int j = 0; j < vsz; j++) {
                //     int num_index = vec_idx[j];
                //     if (num_index == idx) continue;

                //     if (num_index > idx) {
                //         dist = std::min(num_index - idx, nsz + idx - num_index);
                //     } else {
                //         dist = std::min(idx - num_index, num_index + nsz - idx);
                //     }
                //     if (dist < min_dist) {
                //         min_dist = dist;
                //         if (min_dist == 0) break;
                //     }
                // }
                // res[k] = min_dist;
            }
        }
        return res;
    }
};