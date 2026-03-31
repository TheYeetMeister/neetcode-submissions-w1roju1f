class Solution {
    int factorial(int n) {
        int res = 1;

        for (int i = 1; i < n; ++i) {
            res *= i + 1;
        }

        return res;
    }

    void backtracking(unordered_set<int>& chosenValues, vector<int>& curr, 
        vector<int>& nums, vector<vector<int>>& res) {
            if (chosenValues.size() == nums.size()) {
                res.push_back(curr);
                return;
            }

            for (int i = 0; i < nums.size(); ++i) {
                if (chosenValues.find(i) != chosenValues.end()) {
                    continue;
                }

                chosenValues.insert(i);
                curr.push_back(nums[i]);
                backtracking(chosenValues, curr, nums, res);
                curr.pop_back();
                chosenValues.erase(i);
            }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> chosenValues;
        vector<int> curr;
        curr.reserve(nums.size());

        vector<vector<int>> res;
        res.reserve(factorial(nums.size()));

        backtracking(chosenValues, curr, nums, res);

        return res;
    }
};
