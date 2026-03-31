class Solution {
    bool backtrack(vector<int>& nums, int currSum, int sum, int i) {
        if (sum == currSum / 2) {
            return true;
        }

        if (sum > currSum / 2 || i == nums.size()) {
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

        return backtrack(nums, sum, 0, 0);
    }
};
