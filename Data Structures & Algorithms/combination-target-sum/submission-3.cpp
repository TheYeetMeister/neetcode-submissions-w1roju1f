class Solution {
    void backtracking(int i, int currSum, const int target,
                    vector<int>& nums, vector<vector<int>>& res, vector<int>& currPicks) {
        if (currSum == target) {
            res.push_back(currPicks);
            return;
        }

        for (int j = i; j < nums.size(); ++j) {
            if (currSum > target - nums[j]) {
                continue;
            }
            currPicks.push_back(nums[j]);
            backtracking(j, currSum + nums[j], target, nums, res, currPicks);
            currPicks.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res{};
        vector<int> currPicks{};

        backtracking(0, 0, target, nums, res, currPicks);

        return res;
    }
};
