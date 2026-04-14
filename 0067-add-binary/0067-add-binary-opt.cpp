class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty()) return b;
        if (b.empty()) return a;

        int alen = a.length();
        int blen = b.length();
        int i = alen - 1;
        int j = blen - 1;
        std::string res;
        int overflow = 0;
        for (; i >= 0 && j >= 0; i--, j--) {
            int add = a[i] - '0' + b[j] - '0' + overflow;
            if (add >= 2) {
                add -= 2;
                overflow = 1;
            } else {
                overflow = 0;
            }            
            res += add + '0';
        }
        if (i < 0) {
            for (; j >= 0; j--) {
                int add = b[j] - '0' + overflow;
                if (add >= 2) {
                    add -= 2;
                    overflow = 1;
                } else {
                    overflow = 0;
                }
                res += add + '0';
            }
        } else if (j < 0) {
            for (; i >= 0; i--) {
                int add = a[i] - '0' + overflow;
                if (add >= 2) {
                    add -= 2;
                    overflow = 1;
                } else {
                    overflow = 0;
                }
                res += add + '0';
            }
        }
        if (overflow == 1) {
            res += overflow + '0';
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};