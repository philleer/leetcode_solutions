class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) return false;
        if (s.size() == 1) return s[0] >= '0' && s[0] <= '9';

        int start_index = 0;
        while (std::isspace(s[start_index])) ++start_index;
        if (start_index != 0) s = s.substr(start_index);

        int dot_pos = -1;
        int exp_pos = -1;
        int slen = s.length();
        for (int i = 0; i < slen; i++) {
            if (s[i] == '.' && dot_pos != -1) return false;
            if (s[i] == '.' && dot_pos == -1) dot_pos = i;

            if (i == 0) {
                if (s[i] == '.' || s[i] == '+' || s[i] == '-' ||
                    (s[i] >= '0' && s[i] <= '9')) {
                    continue;
                }
                return false;
            }

            if ((s[i - 1] == '-' || s[i - 1] == '+') && (s[i] == '-' || s[i] == '+')) return false;

            if ((s[i] >= '0' && s[i] <= '9') ||
                s[i] == '+' ||
                s[i] == '-' ||
                s[i] == '.') continue;

            if (s[i] == 'e' || s[i] == 'E') {
                if (exp_pos == -1) {
                    exp_pos = i;
                    continue;
                }
            }

            return false;
        }

        if (exp_pos == 0 || (exp_pos == (slen - 1))) return false;

        int cnt = 0;
        if (exp_pos != -1) {
            // Part after exponent notation
            std::string s_part_2 = s.substr(exp_pos + 1);
            for (int j = 0; j < slen - exp_pos - 1; j++) {
                if (j == 0 && (s_part_2[j] == '-' || s_part_2[j] == '+')) continue;
                if (!(s_part_2[j] >= '0' && s_part_2[j] <= '9')) return false;

                ++cnt;
            }
            if (!cnt) return false;

            s = s.substr(0, exp_pos);
        }

        // Part before exponent notation
        slen = s.length();
        cnt = 0;
        if (dot_pos != -1) {
            // decimal number
            for (int k = 0; k < slen; k++) {
                if (k == 0 && (s[k] == '-' || s[k] == '+')) continue;

                if (k != dot_pos && !(s[k] >= '0' && s[k] <= '9')) return false;
                if (k != dot_pos) ++cnt;
            }
            
        } else {
            // integer number
            for (int k = 0; k < slen; k++) {
                if (k == 0 && (s[k] == '+' || s[k] == '-' || s[k] == '.')) continue;

                if (!(s[k] >= '0' && s[k] <= '9')) return false;
                ++cnt;
            }
        }

        return cnt;
    }
};