class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {{""}};
        if (strs.size() == 1) return {strs};

        std::vector<std::vector<std::string>> results;        
        std::unordered_map<std::string, std::vector<std::string>> umap;
        for (std::string &str : strs) {
            std::string tmp(str);
            std::sort(tmp.begin(), tmp.end());
            if (umap.find(tmp) == umap.end()) {
                umap[tmp] = {str};
            } else {
                umap[tmp].push_back(str);
            }
        }
        for (auto it = umap.begin(); it != umap.end(); it++) {
            results.push_back(it->second);
        }

        return results;
    }
};