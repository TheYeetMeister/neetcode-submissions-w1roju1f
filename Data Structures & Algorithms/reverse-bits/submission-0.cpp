class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        ans ^= (n % 2);
        for (unsigned char i = 0; i < 31; ++i) {
            ans <<= 1;
            n >>= 1;
            ans ^= (n % 2);
        }
        return ans;
    }
};
