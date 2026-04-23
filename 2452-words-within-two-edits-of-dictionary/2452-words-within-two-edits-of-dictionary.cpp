class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        if (queries.empty() || dictionary.empty()) return {};

        int qsz = queries.size();
        int dsz = dictionary.size();
        std::set<std::string> cand(dictionary.begin(), dictionary.end());

        std::vector<std::string> res;
        for (auto & q : queries) {
            if (cand.find(q) != cand.end()) {
                res.push_back(q);
            } else {
                for (auto it = cand.begin(); it != cand.end(); it++) {
                    if ((*it).length() != q.length()) continue;

                    int diff_cnt = 0;
                    for (int i = 0; i < q.length(); i++) {
                        if ((*it)[i] != q[i]) {
                            if (++diff_cnt > 2) break;
                        }
                    }
                    if (diff_cnt <= 2) {
                        res.push_back(q);
                        break;
                    }
                }
            }
        }

        return res;
    }
};