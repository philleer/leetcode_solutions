class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) return -1;
        if (x == 0) return x;
        if (x < 4) return 1;

        int res = 2;
        int right = x / 2;
        int left = right;
        long mul = long(left) * long(left);
        while (x < mul) {
            left /= 2;
            mul = long(left) * long(left);
        }

        for (int i = left; i <= right; i++) {
            mul = long(i) * long(i);
            if (mul == x) return i;
            if (mul > x) return i - 1;
        }

        return res;
    }
};