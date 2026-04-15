class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if (words.empty() || (words.size() == 1 && words.back().length() > maxWidth)) return {};
        if (words.size() == 1) {
            return {words.back() + std::string(maxWidth - words.back().size(), ' ')};
        }

        int sz = words.size();
        std::vector<std::string> results;
        std::vector<std::vector<int>> space_poses;
        std::vector<int> space_pos;
        std::string line;
        for (int i = 0; i < sz; i++) {
            if (!line.empty() && (line.length() + words[i].length() + 1 <= maxWidth)) {
                space_pos.push_back(line.length());
                line += " " + words[i];
            } else {
                if (!line.empty()) {
                    results.push_back(line);
                    line.clear();
                    space_poses.push_back(space_pos);
                    space_pos.clear();
                }
                line += words[i];
            }
        }
        if (!line.empty()) {
            space_poses.push_back(space_pos);
            results.push_back(line);
            space_pos.clear();
            line.clear();
        }

        int res_sz = results.size();
        for (int k = 0; k < res_sz; k++) {
            int diff = maxWidth - results[k].length();
            if (diff <= 0) continue;

            if (space_poses[k].empty() || (k == res_sz - 1)) {
                results[k] += std::string(diff, ' ');
            } else {
                int cnt = space_poses[k].size();
                std::string mod_str;
                if (diff % cnt == 0) {
                    diff /= cnt;
                    mod_str += results[k].substr(0, space_poses[k][0] + 1) + std::string(diff, ' ');
                    for (int j = 1; j < cnt; j++) {
                        mod_str += results[k].substr(space_poses[k][j - 1] + 1, space_poses[k][j] - space_poses[k][j - 1]) + std::string(diff, ' ');
                    }
                    mod_str += results[k].substr(space_poses[k].back() + 1);
                } else {
                    if (diff <= cnt) {
                        mod_str += results[k].substr(0, space_poses[k][0] + 1) + std::string(1, ' ');
                        for (int j = 1; j < diff; j++) {
                            mod_str += results[k].substr(space_poses[k][j - 1] + 1, space_poses[k][j] - space_poses[k][j - 1]) + std::string(1, ' ');
                        }
                        mod_str += results[k].substr(space_poses[k][diff - 1] + 1);
                    } else {
                        int rem = diff % cnt;
                        mod_str += results[k].substr(0, space_poses[k][0] + 1) + std::string(diff / cnt + 1, ' ');
                        for (int j = 1; j < cnt; j++) {
                            std::string postfix;
                            if (j < rem) {
                                postfix = std::string( diff / cnt + 1, ' ');
                            } else {
                                postfix = std::string(diff / cnt, ' ');
                            }
                            mod_str += results[k].substr(space_poses[k][j - 1] + 1, space_poses[k][j] - space_poses[k][j - 1]) + postfix;
                        }
                        mod_str += results[k].substr(space_poses[k].back() + 1);
                    }
                }
                results[k] = mod_str;
            }
        }

        return results;
    }
};