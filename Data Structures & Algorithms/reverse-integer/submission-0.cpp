class Solution {
public:
    int reverse(int x) {
        if (!x) return 0;

        int res = x % 10;
        x /= 10;

        while (x) {
            int add = x % 10;
            x /= 10;

            if (res < 0 && res < INT_MIN / 10 - add ||
                res > 0 && res > INT_MAX / 10 - add) {
                    return 0;
            }
            res *= 10;
            res += add;
        }

        return res;
    }
};
