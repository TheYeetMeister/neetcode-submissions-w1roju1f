class Solution {
    void backtracking(int curr, const vector<int>& nums, vector<vector<int>>& res, vector<int>& currVec) {
        if (curr == nums.size()) {
            res.push_back(currVec);
            return;
        }

        //don't add number
        backtracking(curr + 1, nums, res, currVec);

        //add number
        currVec.push_back(nums[curr]);
        backtracking(curr + 1, nums, res, currVec);
        currVec.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{};

        vector<int> currVec{};

        backtracking(0, nums, res, currVec);

        return res;
    }
};
