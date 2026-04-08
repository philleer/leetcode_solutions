class Solution {
public:
    bool recursive(std::string &s, std::string &p, int i, int j, std::vector<std::vector<int>> &memo) {
        if (memo[i][j] != -1) return memo[i][j];

        int slen = s.length();
        int plen = p.length();
        // all matched
        if (i == slen && j == plen) {
            memo[i][j] = true;
            return true;
        }
        // s has more char than p
        if (j == plen) {
            memo[i][j] = false;
            return false;
        }

        // p has more char than s
        if (i == slen) {
            while (j < plen && p[j] == '*') ++j;
            memo[i][j] = (j == plen);
            return memo[i][j];
        }

        bool res = false;
        // normal case
        if (s[i] == p[j] || p[j] == '?') {
            res = recursive(s, p, i + 1, j + 1, memo);
        } else if (p[j] == '*') {
            res = recursive(s, p, i, j + 1, memo) || recursive(s, p, i + 1, j, memo);
        }

        memo[i][j] = res;
        return res;
    }

    bool isMatch(string s, string p) {
        if (s.empty() && p.empty()) return true;
        if (p.empty()) return false;

        int slen = s.length();
        int plen = p.length();
        if (plen == 1 && p.back() == '*') return true;

        std::vector<std::vector<int>> memo(slen + 1, std::vector<int>(plen + 1, -1));
        return recursive(s, p, 0, 0, memo);
    }
};