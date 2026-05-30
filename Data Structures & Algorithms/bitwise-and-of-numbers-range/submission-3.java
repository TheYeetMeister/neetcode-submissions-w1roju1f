class Solution {
    final int bitmask = 0x80000000;
    public int rangeBitwiseAnd(int left, int right) {
        int res = 0;

        boolean match = true;
        for (int i = 0; i < Integer.SIZE; ++i) {
            res <<= 1;
            if ((left & bitmask) != (right & bitmask)) {
                match = false;
            }

            int flip = (match == false || (left & bitmask) == 0)? 0: 1;
            res |= flip;
            left <<= 1;
            right <<= 1;
        }

        return res;
    }
}