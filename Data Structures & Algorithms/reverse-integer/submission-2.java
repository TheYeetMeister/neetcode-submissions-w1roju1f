class Solution {
    public int reverse(int x) {
        int c = 0;

        int intEdge = (x > 0) ? Integer.MAX_VALUE: Integer.MIN_VALUE;
        while (x != 0) {
            int value = x % 10;
            int currComparison = (intEdge - value) / 10;
            if (x > 0 && currComparison < c ||
                x < 0 && currComparison > c) {
                return 0;
            }

            c *= 10;
            x /= 10;

            c += value;
        }

        return c;
    }
}
