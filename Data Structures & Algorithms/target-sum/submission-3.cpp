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
        unordered_map<string, int> cache;
        vector<int> curr;
        curr.push_back(target + nums[0]);
        curr.push_back(target - nums[0]);

        for (int i = 1; i < nums.size(); ++i) {
            vector<int> temp;
            for (int num: curr) {
                temp.push_back(num + nums[i]);
                temp.push_back(num - nums[i]);
            }
            curr = temp;
        }

        int res = 0;

        for (int tar: curr) {
            if (tar == 0) {
                ++res;
            }
        }

        return res;
    }
};
