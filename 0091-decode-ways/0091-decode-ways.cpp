class Solution {
public:
    void recursive(std::string &s, std::vector<int> &path, int start_index, int &cnt, int used_len) {
        if (start_index < 0) {
            int verified = true;
            for (auto &ele : path) {
                if (ele <= 0 || ele > 26) {
                    verified = false;
                    break;
                }
            }
            if (used_len == s.length() && verified) ++cnt;
            return ;
        }

        char ch = s[start_index];
        if (start_index > 0 &&
            s[start_index] > '0' && ch >= '0' &&
            ((s[start_index] <= '1' && ch <= '9') || (s[start_index] == '2' && ch <= '6'))) {
            path.push_back((s[start_index] - '0') * 10 + (ch - '0'));
            recursive(s, path, start_index - 2, cnt, used_len + 2);
            path.pop_back();
        }
        if (ch > '0' && ch <= '9') {
            path.push_back(ch - '0');
            recursive(s, path, start_index - 1, cnt, used_len + 1);
            path.pop_back();
        }
    }

    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        if (s.size() == 1) return 1;

        int slen = s.length();
        std::vector<int> dp(slen + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= slen; i++) {
            if (s[i - 1] >= '1' && s[i - 1] <= '9') {
                dp[i] += dp[i - 1];
            }

            if ((s[i - 2] == '1' && s[i - 1] >= '0' && s[i - 1] <= '9') || (s[i - 2] == '2' && s[i - 1] >= '0' && s[i - 1] <= '6')) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[slen];
    }
};