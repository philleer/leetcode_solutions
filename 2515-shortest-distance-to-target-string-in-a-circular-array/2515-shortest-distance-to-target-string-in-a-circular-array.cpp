class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if (words.empty() || (words.size() == 1 && words.back() != target)) return -1;

        int up_dist = 0;
        bool found = false;
        int sz = words.size();
        for (int i = startIndex; i < sz + startIndex; i++) {
            if (words[i % sz] == target) {
                found = true;
                break;
            }
            ++up_dist;
        }
        if (!found) return -1;

        int down_dist = 0;
        for (int i = startIndex; i > startIndex - sz; i--) {
            if (words[(i + sz) % sz] == target) break;
            ++down_dist;
        }

        return std::min(up_dist, down_dist);
    }
};