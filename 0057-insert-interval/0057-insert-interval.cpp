class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};

        int sz = intervals.size();
        std::vector<std::vector<int>> results;
        int i = 0;
        for (; i < sz; i++) {
            if (intervals[i][0] >= newInterval[0]) break;

            results.push_back(intervals[i]);
        }
        intervals.insert(intervals.begin() + i, newInterval);

        int left = intervals[i][0];
        int right = intervals[i][1];
        for (auto it = intervals.begin() + i; it != intervals.end(); it++) {
            if ((*it)[1] <= right) continue;

            if ((*it)[0] > right) {
                results.emplace_back(std::vector<int>({left, right}));
                left = (*it)[0];
                right = (*it)[1];
            } else if ((*it)[1] > right) {
                right = (*it)[1];
            }
        }
        results.emplace_back(std::vector<int>({left, right}));

        return results;
    }
};