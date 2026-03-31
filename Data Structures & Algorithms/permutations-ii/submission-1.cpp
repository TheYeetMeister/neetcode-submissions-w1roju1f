class Solution {
    unordered_map<int, int> count;
    vector<int> values;
    vector<vector<int>> res;

    void dfs(vector<int>& nums, vector<int>& subset) {
        if (subset.size() == nums.size()) {
            res.push_back(vector<int>(subset));
            return;
        }

        for (int uniqueNum: values) {
            if (count[uniqueNum] > 0) {
                subset.push_back(uniqueNum);
                --count[uniqueNum];
                dfs(nums, subset);
                ++count[uniqueNum];
                subset.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (int num: nums) {
            if (++count[num] == 1) {
                values.push_back(num);
            }
        }

        vector<int> subset;

        dfs(nums, subset);

        return res;
    }
};