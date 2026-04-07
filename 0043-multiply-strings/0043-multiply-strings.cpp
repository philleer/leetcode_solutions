class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        if (len1 < len2) {
            std::swap(num1, num2);
            std::swap(len1, len2);
        }

        if (len2 == 1 && num2.back() == '0') return num2;
        if (len2 == 1 && num2.back() == '1') return num1;

        std::string result;
        int overflow = 0;
        std::vector<std::string> single_results;
        for (int i = len2 - 1; i >= 0; i--) {
            int val = num2[i] - '0';
            if (val == 0) continue;

            std::string cur_res;
            overflow = 0;
            for (int k = 0; k < len2 - 1 - i; k++) {
                cur_res += '0';
            }
            for (int j = len1 - 1; j >= 0; j--) {
                int cur = val * (num1[j] - '0') + overflow;
                overflow = cur / 10;
                cur_res += cur % 10 + '0';
            }
            if (overflow > 0) {
                cur_res += overflow + '0';
            }
            single_results.push_back(cur_res);
        }

        int max_len = single_results.back().length();
        overflow = 0;
        for (int i = 0; i < max_len; i++) {
            int sum = overflow;
            for (auto it = single_results.begin(); it != single_results.end(); it++) {
                if (it->length() <= i) continue;

                sum += (*it)[i] - '0';
            }
            overflow = sum / 10;
            result += sum % 10 + '0';
        }
        if (overflow > 0) {
            result += overflow + '0';
        }
        std::reverse(result.begin(), result.end());

        return result;
    }
};