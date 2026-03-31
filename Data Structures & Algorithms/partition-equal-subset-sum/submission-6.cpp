class Solution {
    bool backtrack(vector<int>& nums, int currSum, int sum, int i) {
        if (sum == currSum / 2) {
            return true;
        }

        if (i == nums.size()) {
            return false;
        }

        bool include = backtrack(nums, currSum, sum, i + 1);

        int curr = nums[i];
        bool dontInclude = backtrack(nums, currSum, sum + curr, i + 1);
        nums[i] = curr;

        return include || dontInclude;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int num: nums) {
            sum += num;
        }

        if (sum % 2 == 1) {
            return false;
        }

        vector<vector<bool>> dp(nums.size(), vector<bool>(sum / 2, 0));

        dp[0][nums[0]] = true;

        for (int i = 1; i < nums.size(); ++i) {
            dp[i][nums[i]] = true;
            if (nums[i] == sum / 2) {
                return true;
            }

            for (int j = 0; j < sum / 2; ++j) {
                if (!dp[i - 1][j]) {
                    continue;
                }

                dp[i][j] = true;

                if (j + nums[i] == sum / 2) {
                    return true;
                }

                if (j + nums[i] < sum / 2) {
                    dp[i][j + nums[i]] = true; 
                }
            }
        }

        return false;
    }
};
