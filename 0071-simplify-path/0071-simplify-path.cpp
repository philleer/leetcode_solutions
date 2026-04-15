class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty() || (path.length() == 1 && path.back() != '/')) return "";
        if (path.length() == 1) return "/";

        std::stack<std::string> sstr;
        int slen = path.length();
        std::string cur_str;
        for (int i = 0; i < slen; i++) {
            if (i > 0 && path[i - 1] == '/' && path[i] == '/') continue;

            if (path[i] != '/') {
                cur_str += path[i];
                if (i == slen - 1) {
                    sstr.push(cur_str);
                    cur_str.clear();
                }
            } else if (path[i] == '/' && !cur_str.empty()) {
                if (cur_str == ".") {
                    cur_str.clear();
                    continue;
                }
                if (cur_str == "..") {
                    if (!sstr.empty()) {
                        sstr.pop();
                    }
                    cur_str.clear();
                    continue;
                }
                sstr.push(cur_str);
                cur_str.clear();
            }
        }

        if (sstr.empty()) return "/";

        std::string result;
        while (!sstr.empty()) {
            cur_str = sstr.top();
            sstr.pop();
            if (cur_str == ".") continue;
            if (cur_str == "..") {
                if (!sstr.empty()) {
                    sstr.pop();
                } else {
                    result = "/" + result;
                }   
                continue;
            }
            
            result = "/" + cur_str + result;
        }
        if (result.empty()) return "/";

        return result;
    }
};