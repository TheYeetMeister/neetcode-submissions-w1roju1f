class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        int c = left;
        for (long i = left + 1; i <= right; ++i) {
            c &= i;

            if (c == 0) {
                return 0;
            }
        }
        return c;
    }
}