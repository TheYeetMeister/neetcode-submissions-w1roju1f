class Solution {
    void backtracking(int i, int currSum, const int target,
                    vector<int>& nums, vector<vector<int>>& res, vector<int>& currPicks) {
        if (currSum == target) {
            res.push_back(currPicks);
            return;
        }

        if (i == nums.size()) {
            return;
        }

        backtracking(i + 1, currSum, target,
            nums, res, currPicks);

        int j = 0;

        for (; currSum < target - nums[i] + 1; ++j) {
            currSum += nums[i];
            currPicks.push_back(nums[i]);
            backtracking(i + 1, currSum, target,
                nums, res, currPicks);
        }

        for (int k = 0; k < j; ++k) {
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
