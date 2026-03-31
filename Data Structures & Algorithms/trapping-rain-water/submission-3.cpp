class Solution {
public:
    int trap(vector<int>& height) {
        //better two point constant memory solution
        int left = 0;
        int right = height.size() - 1;

        int maxLeft = height[left];
        int maxRight = height[right];

        int totalWater = 0;

        while (left < right) {
            int currentWater = 0;

            if (maxLeft < maxRight) {
                ++left;
                maxLeft = max(height[left], maxLeft);
                currentWater = maxLeft - height[left];
            } else {
                --right;
                maxRight = max(height[right], maxRight);
                currentWater = maxRight - height[right];
            }

            totalWater += currentWater;
        }

        return totalWater;
        /*
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
        */
    }
};
