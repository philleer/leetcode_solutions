class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        if (sz <= 2) return 0;

        int result = 0;
        std::vector<std::pair<int, int>> threshs;

        threshs.emplace_back(height[0], 0);
        for (int i = 1; i < sz; i++) {
            std::pair<int, int> &last = threshs.back();
            if ((last.second + 1 == i) && height[i] >= last.first) {
                threshs.back() = {height[i], i};
            } else if (height[i] > height[i - 1]) {
                threshs.emplace_back(height[i], i);
            }
        }
        if (threshs.size() == 1) {
            result = 0;
        } else {
            std::vector<std::pair<int, int>> filtered_threshs;
            while (true) {
                filtered_threshs.clear();
                filtered_threshs.push_back(threshs[0]);
                for (int k = 1; k < threshs.size() - 1; k++) {
                    if (threshs[k].first <= filtered_threshs.back().first &&
                        threshs[k].first <= threshs[k + 1].first) continue;
                    
                    filtered_threshs.push_back(threshs[k]);
                }
                filtered_threshs.push_back(threshs.back());
                if (filtered_threshs.size() == threshs.size()) break;
                threshs = filtered_threshs;
            }

            for (int k = 1; k < filtered_threshs.size(); k++) {
                int left = filtered_threshs[k - 1].second;
                int right = filtered_threshs[k].second;
                int bar = std::min(filtered_threshs[k - 1].first, filtered_threshs[k].first);
                for (int i = left + 1; i < right; i++) {
                    int diff = bar - height[i];
                    result += (diff > 0 ? diff : 0);
                }
            }
        }

        return result;
    }
};