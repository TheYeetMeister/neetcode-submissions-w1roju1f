class Solution {
public:
    int trap(vector<int>& height) {
        int totalWater = 0;

        for (int i = 0; i < height.size(); ++i) {
            int leftMaxHeight = 0;
            for (int j = i - 1; j >= 0; --j) {
                leftMaxHeight = max(leftMaxHeight, height[j]);
            }

            int rightMaxHeight = 0;
            for (int j = i + 1; j < height.size(); ++j) {
                rightMaxHeight = max(rightMaxHeight, height[j]);
            }

            int waterCaught = min(leftMaxHeight, rightMaxHeight) - height[i];

            if (waterCaught > 0) {
                totalWater += waterCaught;
            }
        }

        return totalWater;
    }
};
