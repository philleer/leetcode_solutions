class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {{}};
        if (intervals.size() == 1) return intervals;

        int sz = intervals.size();
        std::sort(intervals.begin(), intervals.end(), [] (std::vector<int> &a, std::vector<int> &b) {
            return ((a[0] != b[0]) ? (a[0] < b[0]) : (a[1] < b[1]));
        });

        int left = INT_MAX;
        int right = INT_MIN;
        std::vector<std::vector<int>> results;
        for (int i = 0; i < sz; i++) {
            if (intervals[i][1] <= right) continue;
            if (intervals[i][0] < left || intervals[i][0] > right) {
                left = intervals[i][0];
            }
            if (intervals[i][1] > right || intervals[i][0] > right) {
                right = intervals[i][1];
            }
            for (int j = i + 1; j < sz; j++) {
                if (intervals[j][1] <= left) continue;
                if (intervals[j][0] <= right) {
                    right = std::max(intervals[j][1], right);
                } else {
                    results.emplace_back(std::vector<int>({left, right}));
                    break;
                }
            }
        }
        if ((!results.empty() && (results.back()[0] != left || results.back()[1] != right)) ||
            (results.empty() && left != INT_MAX && right != INT_MIN)) {
            results.emplace_back(std::vector<int>({left, right}));
        }

        return results;
    }
};