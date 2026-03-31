class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> takeFirst(nums.size() - 1);
        vector<int> takeSecond(nums.size() - 1);

        takeFirst[0] = nums[0];
        takeFirst[1] = max(nums[0], nums[1]);

        takeSecond[0] = nums[1];
        takeSecond[1] = max(nums[1], nums[2]);

        for (int i = 2; i < nums.size() - 1; ++i) {
            takeFirst[i] = max(nums[i] + takeFirst[i - 2], takeFirst[i - 1]);
            takeSecond[i] = max(nums[i + 1] + takeSecond[i - 2], takeSecond[i - 1]);
        }

        return max(takeFirst.back(), takeSecond.back());
    }

    //recurssive solution
    int findMax(vector<int>& nums, int i, int maxInd) {
        if (i >= maxInd) {
            return 0;
        }

        int take = nums[i] + findMax(nums, i + 2, maxInd);
        int dontTake = findMax(nums, i + 1, maxInd);

        return max(take, dontTake);
    }
};
