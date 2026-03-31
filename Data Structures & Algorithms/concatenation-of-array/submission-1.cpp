class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> returnNum;
        returnNum.reserve(nums.size() * 2);
        for (int j = 0; j < 2; ++j) {
            for (unsigned i = 0; i < nums.size(); ++i) {
                returnNum.push_back(nums[i]);
            }
        }
        return returnNum;
    }
};