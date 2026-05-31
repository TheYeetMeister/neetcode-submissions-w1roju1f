class Solution {
    public long minEnd(int n, int x) {
        long scanner = 1;
        long res = x;

        --n;
        while (n != 0) {
            if ((x & scanner) == 0) {
                res |= ((n & 1) != 0)? scanner: 0;

                n >>= 1;
            }
            scanner <<= 1;
        }

        return res;
    }
}