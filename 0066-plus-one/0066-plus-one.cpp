class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return {};
        if (digits.size() == 1 && digits.back() < 9) return {digits.back() + 1};

        int sz = digits.size();
        int overflow = 1;
        for (int i = sz - 1; i >= 0; i--) {
            digits[i] += overflow;
            if (digits[i] >= 10) {
                digits[i] -= 10;
                overflow = 1;
            } else {
                overflow = 0;
            }
        }
        if (overflow == 1) {
            digits.insert(digits.begin(), overflow);
        }

        return digits;
    }
};