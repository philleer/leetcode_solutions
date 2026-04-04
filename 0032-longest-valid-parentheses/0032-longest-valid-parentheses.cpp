class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        int slen = s.length();
        if (slen <= 1) return 0;

        std::stack<int> ss_index;
        int max_len = 0;
        int cur = 0;
        for (int i = 0; i < slen; i++) {
            if (!ss_index.empty() && (s[ss_index.top()] == '(' && s[i] == ')')) {
                ss_index.pop();
            } else {
                ss_index.push(i);
            }
        }

        if (ss_index.empty()) return slen;

        cur = slen;
        while (!ss_index.empty()) {
            max_len = std::max(max_len, cur - ss_index.top() - 1);
            cur = ss_index.top();
            ss_index.pop();
        }

        return std::max(max_len, cur);
    }
};