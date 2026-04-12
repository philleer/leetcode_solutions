class Solution {
public:
    std::string permutation(const int &n, const int &k, int &cnt, std::vector<bool> &used, std::string path, bool &done) {
        if (path.length() == n) {
            if ((++cnt) == k) {
                done = true;
            }
            return path;
        }

        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;

            used[i] = true;
            path += std::to_string(i);
            std::string tmp = permutation(n, k, cnt, used, path, done);
            if (done) return tmp;
            used[i] = false;
            path.pop_back();
        }

        return path;
    }

    string getPermutation(int n, int k) {
        if (n == 1) return ((k == 1) ? "1" : "");
        if (n == 2) return ((k == 1) ? "12" : ((k == 2) ? "21" : ""));

        int cnt = 0;
        std::vector<bool> used(n+1, false);
        bool done = false;
        return permutation(n, k, cnt, used, "", done);
    }
};