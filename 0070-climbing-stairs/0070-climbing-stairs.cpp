class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int last_two = 1;
        int last_one = 2;
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            cnt = last_one + last_two;
            last_two = last_one;
            last_one = cnt;
        }

        return cnt;
    }
};