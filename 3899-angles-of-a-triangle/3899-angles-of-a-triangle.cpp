class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        if (sides.empty() || sides.size() < 3) return {};

        int a = sides[0];
        int b = sides[1];
        int c = sides[2];

        if ((a + b <= c) || (a + c <= b) || (b + c <= a)) return {};
        if (a == b && a == c) return {60.000000f, 60.000000f, 60.000000f};

        const double PI = 3.141592653589;
        const double RAD2DEG = 180.f / PI;
        double sq_a = 1.f * a * a;
        double sq_b = 1.f * b * b;
        double sq_c = 1.f * c * c;

        double angle_a = std::acos(0.5 * (sq_c + sq_b - sq_a) / (1.f * b * c)) * RAD2DEG;
        double angle_b = std::acos(0.5 * (sq_a + sq_c - sq_b) / (1.f * a * c)) * RAD2DEG;
        double angle_c = std::acos(0.5 * (sq_a + sq_b - sq_c) / (1.f * a * b)) * RAD2DEG;

        std::vector<double> results = {angle_a, angle_b, angle_c};
        std::sort(results.begin(), results.end());

        return results;
    }
};