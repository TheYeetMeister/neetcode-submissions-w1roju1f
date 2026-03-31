class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> returnNum = nums;
        for (unsigned i = 0; i < nums.size(); ++i) {
            returnNum.push_back(nums[i]);
        }
        return returnNum;
    }
};