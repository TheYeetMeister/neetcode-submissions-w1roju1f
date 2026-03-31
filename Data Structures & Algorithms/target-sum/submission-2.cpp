class Solution {
    unordered_map<string, int> cache;
    int dfs(vector<int>& nums, int target, int i) {
        if (i == nums.size() && target == 0) {
            return 1;
        } else if (i == nums.size()) {
            return 0;
        }

        string index = to_string(target) + "-" + to_string(i);
        if (cache[index]) {
            return cache[index];
        }

        int add = dfs(nums, target + nums[i], i + 1);
        int sub = dfs(nums, target - nums[i], i + 1);
        cache[index] = add + sub;

        return cache[index];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0);
    }
};
