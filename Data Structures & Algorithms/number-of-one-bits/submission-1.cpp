class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i = 0;

        while (n) {
            i += n & 1;
            n = n >> 1;
        }

        return i;
    }
};
