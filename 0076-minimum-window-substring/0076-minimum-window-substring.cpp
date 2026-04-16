class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty() || s.length() < t.length()) return "";
        if (s == t) return s;

        int slen = s.length();
        int tlen = t.length();
        std::unordered_map<char, int> tmap;
        for (char & ch : t) ++tmap[ch];

        int min_len = INT_MAX;
        int win_len = 0;
        int res_start = INT_MIN;
        int left = 0;
        int match = 0;
        std::unordered_map<char, int> smap;
        for (int right = 0; right < slen; right++) {
            char ch = s[right];

            if (tmap.find(ch) != tmap.end()) {
                ++smap[ch];
                if (smap[ch] == tmap[ch]) {
                    ++match;
                }
            }

            while (match == tmap.size()) {
                win_len = right - left + 1;
                if (win_len < min_len) {
                    min_len = win_len;
                    res_start = left;
                }

                char d = s[left];
                if (tmap.find(d) != tmap.end()) {
                    if (smap[d] == tmap[d]) {
                        --match;
                    }
                    --smap[d];
                }
                ++left;
            }
        }

        if (res_start == INT_MIN || min_len == INT_MAX) return "";
        return s.substr(res_start, min_len);

        // while (left <= right && right < slen) {
        //     smap.clear();
        //     cnt = 0;
        //     bool cand_valid = true;
        //     for (int i = left; i < slen; i++) {
        //         if (tmap.find(s[i]) != tmap.end()) {
        //             ++smap[s[i]];
        //             ++cnt;
        //             if (smap[s[i]] >= tmap[s[i]] && smap.size() >= tmap.size() && cnt >= tlen) {
        //                 cand_valid = true;
        //                 for (auto it = smap.begin(); it != smap.end(); it++) {
        //                     if (tmap[it->first] > it->second) {
        //                         cand_valid = false;
        //                         break;
        //                     }
        //                 }
        //                 if (cand_valid){
        //                     right = i;
        //                     break;
        //                 } else {
        //                     right = slen - 1;
        //                 }
        //             }
        //         } else if (i == left) {
        //             ++left;
        //         }
        //     }

        //     if (smap.size() < tmap.size() || cnt < tlen) break;
        //     win_len = right - left + 1;
        //     if(win_len >= min_len) {
        //         ++left;
        //         continue;
        //     }

        //     bool valid = true;
        //     for (auto it = tmap.begin(); it != tmap.end(); it++) {
        //         if (smap.find(it->first) == smap.end() || smap[it->first] < it->second) {
        //             valid = false;
        //             break;
        //         }
        //     }

        //     if (valid && win_len < min_len) {
        //         min_len = win_len;
        //         res_start = left;
        //     }

        //     ++left;
        // }

        // if (res_start == INT_MIN) return "";
        // return s.substr(res_start, min_len);

        // int left = -1;
        // int right = slen;
        // for (int i = 0; i < slen; i++) {
        //     if (tmap.find(s[i]) != tmap.end()) {
        //         left = i;
        //         break;
        //     }
        // }
        // if (left == -1) return "";
        // if (tlen == 1 && left != -1) return t;

        // for (int i = slen - 1; i >= left; i--) {
        //     if (tmap.find(s[i]) != tmap.end()) {
        //         right = i;
        //         break;
        //     }
        // }
        // if (right - left + 1 < tlen) return "";

        // std::unordered_map<char, int> smap;
        // for (char & ch : s) ++smap[ch];
        // for (auto it = tmap.begin(); it != tmap.end(); it++) {
        //     if (smap.find(it->first) == smap.end() || smap[it->first] < it->second) {
        //         return "";
        //     }
        // }

        // // Solution (1) : naive method, TLE, time complexity O(n^3)
        // int min_window_len = INT_MAX;
        // std::pair<int, int> result;
        // for (int i = left; i <= right - tlen + 1; i++) {
        //     for (int j = i + tlen - 1; j <= right; j++) {
        //         bool valid = true;
        //         int window_len = j - i + 1;
        //         smap.clear();
        //         int cnt = 0;
        //         for (int k = i; k <= j; k++) {
        //             ++smap[s[k]];
        //             if (tmap.find(s[k]) != tmap.end()) {
        //                 ++cnt;
        //             }
        //         }

        //         for (auto it = tmap.begin(); it != tmap.end(); it++) {
        //             if (smap.find(it->first) == smap.end() || smap[it->first] < it->second) {
        //                 valid = false;
        //                 break;
        //             }
        //         }
        //         if (valid && window_len < min_window_len) {
        //             min_window_len = window_len;
        //             result = {i, j};
        //         }
        //     }
        // }

        // return s.substr(result.first, result.second - result.first + 1);
    }
};