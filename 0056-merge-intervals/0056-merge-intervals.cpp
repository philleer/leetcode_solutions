class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {{}};
        if (intervals.size() == 1) return intervals;

        int sz = intervals.size();
        std::vector<std::pair<int, int>> begin_intervals(sz);
        std::vector<std::pair<int, int>> end_intervals;
        for (int i = 0; i < sz; i++) {
            begin_intervals[i] = {intervals[i][0], intervals[i][1]};
        }
        end_intervals.assign(begin_intervals.begin(), begin_intervals.end());
        std::sort(begin_intervals.begin(), begin_intervals.end(), [] (std::pair<int, int> &a, std::pair<int, int> &b) {
            return ((a.first != b.first) ? (a.first < b.first) : (a.second < b.second));
        });
        std::sort(end_intervals.begin(), end_intervals.end(), [] (std::pair<int, int> &a, std::pair<int, int> &b) {
            return ((a.first != b.first) ? (a.first < b.first) : (a.second < b.second));
        });

        int left = INT_MAX;
        int right = INT_MIN;
        std::vector<std::vector<int>> results;
        for (int i = 0; i < sz; i++) {
            if (begin_intervals[i].second <= right) continue;
            if (begin_intervals[i].first < left || begin_intervals[i].first > right) {
                left = begin_intervals[i].first;
            }
            if (begin_intervals[i].second > right || begin_intervals[i].first > right) {
                right = begin_intervals[i].second;
            }
            for (int j = 0; j < sz; j++) {
                if (end_intervals[j].second <= left) continue;
                if (end_intervals[j].first <= right) {
                    right = std::max(end_intervals[j].second, right);
                } else {
                    results.emplace_back(std::vector<int>({left, right}));
                    break;
                }
            }
        }
        if (!results.empty() && (results.back()[0] != left || results.back()[1] != right)) {
            results.emplace_back(std::vector<int>({left, right}));
        } else if (results.empty() && left != INT_MAX && right != INT_MIN) {
            results.emplace_back(std::vector<int>({left, right}));
        }

        return results;
    }
};