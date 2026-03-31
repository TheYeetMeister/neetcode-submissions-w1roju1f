class Solution {
    public int maxArea(int[] heights) {
        int l = 0;
        int r = heights.length - 1;

        int mostWater = 0;

        while (l < r) {
            mostWater = Math.max((r - l) * Math.min(heights[l], heights[r]), mostWater);
            if (heights[l] < heights[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return mostWater;
    }
}
