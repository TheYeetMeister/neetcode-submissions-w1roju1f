class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefixMax(height.size(), 0);
        vector<int> suffixMax(height.size(), 0);

        int totalWater = 0;

        int currMax = 0;
        for (int i = 0; i < height.size(); ++i) {
            prefixMax[i] = max(height[i], currMax);
            currMax = prefixMax[i];
        }

        currMax = 0;
        for (int i = height.size() - 1; i >= 0; --i) {
            suffixMax[i] = max(height[i], currMax);
            currMax = suffixMax[i];
        }

        for (int i = 0; i < height.size(); ++i) {
            int waterHold = min(suffixMax[i], prefixMax[i]) - height[i];

            if (waterHold > 0) {
                totalWater += waterHold;
            }
        }

        return totalWater;
    }
};
