class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};

        int sz = intervals.size();
        int i = 0;
        for (; i < sz; i++) {
            if (intervals[i][0] >= newInterval[0]) break;
        }
        intervals.insert(intervals.begin() + i, newInterval);

        int left = intervals[0][0];
        int right = intervals[0][1];
        std::vector<std::vector<int>> results;
        for (auto it = intervals.begin(); it != intervals.end(); it++) {
            if ((*it)[1] <= right) continue;

            if ((*it)[0] > right) {
                results.emplace_back(std::vector<int>({left, right}));
                left = (*it)[0];
                right = (*it)[1];
            } else if ((*it)[1] > right) {
                right = (*it)[1];
            }
        }

        if ((!results.empty() && (results.back()[0] != left || results.back()[1] != right)) ||
            results.empty()) {
            results.emplace_back(std::vector<int>({left, right}));
        }

        return results;
    }
};