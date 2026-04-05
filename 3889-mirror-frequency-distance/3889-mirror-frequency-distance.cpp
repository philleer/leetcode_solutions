class Solution {
public:
    int mirrorFrequency(string s) {
        int slen = s.length();
        if (slen == 1) return 1;

        std::unordered_map<char, int> umap;
        for (auto & ch : s) ++umap[ch];

        std::string mirror_str;
        for (auto & ch : s) {
            if (ch >= '0' && ch <= '9') {
                mirror_str += '0' + ('9' - ch);
            } else if (ch >= 'a' && ch <= 'z') {
                mirror_str += 'a' + ('z' - ch);
            }
        }
        if (mirror_str == s) return 0;

        int sum_freq_cnt = 0;
        std::set<char> cset;
        for (int i = 0; i < slen; i++) {
            if (cset.find(s[i]) == cset.end() && cset.find(mirror_str[i]) == cset.end()) {
                if (umap.find(mirror_str[i]) != umap.end()) {
                    sum_freq_cnt += std::abs(umap[s[i]] - umap[mirror_str[i]]);
                } else {
                    sum_freq_cnt += umap[s[i]];
                }
                cset.insert(s[i]);
            }
        }

        return sum_freq_cnt;
    }
};