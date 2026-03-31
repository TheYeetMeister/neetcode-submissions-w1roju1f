class Solution {
    int dfs(vector<int>& nums, int target, int i) {
        if (i == nums.size() && target == 0) {
            return 1;
        } else if (i == nums.size()) {
            return 0;
        }

        int add = dfs(nums, target + nums[i], i + 1);
        int sub = dfs(nums, target - nums[i], i + 1);

        return add + sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0);
    }
};
