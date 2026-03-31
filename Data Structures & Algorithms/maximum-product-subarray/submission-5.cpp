class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;

        int currMax = 1;
        int currMin = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }
            int nextMax = currMax * nums[i];
            int nextMin = currMin * nums[i];

            currMax = max(nextMax, nums[i]);
            currMin = min(nextMin, nums[i]);

            res = max(currMax, res);
        }

        return res;
    }
};
