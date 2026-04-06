class Solution {
public:
    string countAndSay(int n) {
        std::vector<std::string> results;

        results.push_back("1");
        for (int i = 1; i < n; i++) {
            std::string last_str = results.back();
            int cnt = 1;
            std::string cur_str;
            for (int k = 1; k < last_str.size(); k++) {
                if (last_str[k] == last_str[k - 1]) {
                    ++cnt;
                } else {
                    cur_str += std::to_string(cnt) + last_str[k - 1];
                    cnt = 1;
                }
            }
            cur_str += std::to_string(cnt) + last_str.back();
            results.push_back(cur_str);
        }

        return results.back();
    }
};