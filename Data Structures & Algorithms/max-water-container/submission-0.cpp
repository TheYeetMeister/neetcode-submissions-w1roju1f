class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxAmount = 0;

        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int area = (right - left) * min(heights[left], heights[right]);

            maxAmount = max(area, maxAmount);

            if (heights[left] > heights[right]) {
                --right;
            } else {
                ++left;
            }
        }

        return maxAmount;
    }
};
