class Solution {
public:
    int mirrorDistance(int n) {
        if (n < 0) return -1;
        if (n < 10) return 0;

        int mirror_num = 0;
        int num = n;
        while (num) {
            mirror_num = mirror_num * 10 + num % 10;
            num /= 10;
        }

        return std::abs(mirror_num - n);
    }
};