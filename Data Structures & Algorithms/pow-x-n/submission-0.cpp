class Solution {
    double exp(double x, int n) {
        int currentPower = 1;
        unordered_map<int, double> values;
        values[currentPower] = x;

        while (currentPower * 2 <= n) {
            x *= x;
            currentPower *= 2;
            values[currentPower] = x;
        }
        int leftOverPower = currentPower;

        while (currentPower < n) {
            while (currentPower + leftOverPower > n) {
                leftOverPower /= 2;
            }

            x *= values[leftOverPower];
            currentPower += leftOverPower;
        } 

        return x;
    }
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }

        if (n < 0) {
            x = 1 / x;
            n *= -1;
        }

        return exp(x, n);
    }
};
