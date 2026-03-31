class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i = 0;

        while (n) {
            i += n % 2;
            n /= 2;
        }

        return i;
    }
};
