class Solution {
    void backtracking(const int i, vector<int>& currVec, vector<int>& nums, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(currVec);
            return;
        }

        currVec.push_back(nums[i]);
        backtracking(i + 1, currVec, nums, res);
        currVec.pop_back();

        int j = i + 1;
        for (; j < nums.size() && nums[i] == nums[j]; ++j);
        backtracking(j, currVec, nums, res);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res{};
        vector<int> currVec{};

        backtracking(0, currVec, nums, res);

        return res;
    }
};
