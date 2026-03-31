class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), nums.size() + 1);
        dp.back() = 0;

        for (int i = nums.size() - 2; i >= 0; --i) {
            for (int j = 0; j < nums[i]; ++j) {
                if (j + i + 1 == nums.size()) {
                    break;
                }

                dp[i] = min(dp[i], 1 + dp[i + j + 1]);
            }
        }

        return dp[0];
    }
};
