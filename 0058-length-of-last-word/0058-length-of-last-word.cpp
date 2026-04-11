class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return -1;

        int right = s.length() - 1;
        while (right >= 0 && std::isspace(s[right])) --right;

        int left = right - 1;
        while (left >= 0 && !std::isspace(s[left])) --left;
        return right - left;
    }
};