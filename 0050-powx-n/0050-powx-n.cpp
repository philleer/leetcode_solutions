class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.f) return 0.f;
        if (n == 0) return 1.f;
        if (n == 1) return x;
        if (n == 2) return x * x;

        double sign = (x > 0.0f ? 1.0f : ((n % 2 != 0) ? -1.f : 1.f));
        bool frac = false;
        if (x < 0.f) x = -x;
        if (x == 1.f) return sign * x;

        if (n < 0 && n > INT_MIN) {
            frac = true;
            n = -n;
        } else if (n == INT_MIN) {
            frac = true;
            x = x * x;
            n = INT_MAX / 2 + 1;
        }

        double res = myPow(x, n / 2);
        res = res * res;
        res *= ((n & 1) ? x : 1.f);

        return sign * (frac ? (1.0 / res) : res);
    }
};