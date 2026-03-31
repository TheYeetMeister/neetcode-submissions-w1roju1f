class Solution {
    int backtr(vector<int>& nums, int i, int prev) {
        if (i >= nums.size()) {
            return 0;
        }

        int ret = INT_MIN;
        for (; i < nums.size(); ++i) {
            if (nums[i] > prev) {
                ret = max(ret, 1 + backtr(nums, i + 1, nums[i]));
            }
        }

        return ret;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        int res = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] > nums[i]) {
                    dp[j] = max(dp[j], dp[i] + 1);
                    res = max(res, dp[j]);
                }
            }
        }

        return res;
    }
};
