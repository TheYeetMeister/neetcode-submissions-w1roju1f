class Solution {
    void backtracking(int i, int currSum, const int target, 
                vector<int>& nums, vector<vector<int>>& res, vector<int>& currNums) {
        if (currSum == target) {
            res.push_back(currNums);
            return;
        }

        if (nums.size() == i) {
            return;
        }

        if (currSum <= target - nums[i]) {
            currNums.push_back(nums[i]);
            backtracking(i + 1, currSum + nums[i], target,
                nums, res, currNums);
            currNums.pop_back();
        }

        int j = i + 1;
        for (; nums.size() > j && nums[j] == nums[i]; ++j);
        backtracking(j, currSum, target,
                nums, res, currNums);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res{};
        vector<int> currPicks {};

        backtracking(0, 0, target, candidates, res, currPicks);

        return res;
    }
};
