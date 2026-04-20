class Solution {
public:
    int maxDistance(vector<int>& colors) {
        if (colors.empty() || colors.size() == 1) return 0;

        int len = colors.size();
        int max_dist = INT_MIN;
        for (int i = len - 1; i > 0; i--) {
            if (colors[i] == colors[0] || i <= max_dist) continue;
            max_dist = std::max(i, max_dist);
        }

        for (int j = 0; j < len - 1; j++) {
            if (colors[j] == colors[len - 1] || j + max_dist >= len - 1) continue;

            max_dist = std::max(len - 1 - j, max_dist);
        }
        return max_dist == INT_MIN ? 0 : max_dist;
    }
};