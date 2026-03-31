class Solution {
    private int calculateWaterHeight(int tallestR, int tallestL, int floor) {
        return Math.max(Math.min(tallestR, tallestL) - floor, 0);
    }

    public int trap(int[] height) {
        int l = 0, r = height.length - 1;
        int tallestL = height[l], tallestR = height[r];

        int res = 0;

        while (l < r) {
            int lowestWall = Math.min(tallestR, tallestL);

            if (height[l] > height[r]) {
                int newHeight = height[--r];
                res += calculateWaterHeight(tallestR, tallestL, newHeight);
                tallestR = Math.max(tallestR, newHeight);
            } else {
                int newHeight = height[++l];
                res += calculateWaterHeight(tallestR, tallestL, newHeight);
                tallestL = Math.max(tallestL, newHeight);
            }
        }

        return res;
    }
}
