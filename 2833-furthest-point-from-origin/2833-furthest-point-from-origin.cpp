class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        if (moves.empty() || moves.size() < 2) return moves.size();

        int sz = moves.size();
        std::vector<int> cnts(3, 0);
        for (int i = 0; i < sz; i++) {
            if (moves[i] == 'L') {
                ++cnts[0];
            } else if (moves[i] == 'R') {
                ++cnts[1];
            } else {
                ++cnts[2];
            }
        }

        if (cnts[0] != cnts[1]) return std::max(cnts[0], cnts[1]) + cnts[2] - std::min(cnts[0], cnts[1]);

        return cnts[2];
    }
};