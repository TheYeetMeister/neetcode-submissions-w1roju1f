class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            int tar = target - nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] == tar) {
                    return std::vector<int>{i, j};
                }
            }
        }
        return std::vector<int>{};
    }
};
