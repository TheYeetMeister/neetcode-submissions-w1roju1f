class Solution {
    public int trap(int[] height) {
        int l = 0, r = height.length - 1;
        int tallestL = height[l], tallestR = height[r];

        int res = 0;

        while (l < r) {
            if (tallestL > tallestR) {
                int newHeight = height[--r];
                res += Math.max(tallestR - newHeight, 0);
                tallestR = Math.max(tallestR, newHeight);
            } else {
                int newHeight = height[++l];
                res += Math.max(tallestL - newHeight, 0);;
                tallestL = Math.max(tallestL, newHeight);
            }
        }

        return res;
    }
}
