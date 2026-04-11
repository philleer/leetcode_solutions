class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {{}};
        if (intervals.size() == 1) return intervals;

        int sz = intervals.size();
        std::sort(intervals.begin(), intervals.end(), [] (std::vector<int> &a, std::vector<int> &b) {
            return ((a[0] != b[0]) ? (a[0] < b[0]) : (a[1] < b[1]));
        });

        int left = intervals[0][0];
        int right = intervals[0][1];
        std::vector<std::vector<int>> results;
        for (int i = 1; i < sz; i++) {
            if (intervals[i][1] <= right) continue;
            if (intervals[i][0] > right) {
                results.emplace_back(std::vector<int>({left, right}));
                left = intervals[i][0];
                right = intervals[i][1];
            } else if (intervals[i][1] > right) {
                right = intervals[i][1];
            }
        }
        if ((!results.empty() && (results.back()[0] != left || results.back()[1] != right)) ||
            (results.empty() && left != INT_MAX && right != INT_MIN)) {
            results.emplace_back(std::vector<int>({left, right}));
        }

        return results;
    }
};