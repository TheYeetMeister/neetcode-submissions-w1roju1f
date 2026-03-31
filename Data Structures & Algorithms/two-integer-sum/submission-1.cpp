#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> pastValues;

        for (int i = 0; i < nums.size(); ++i) {
            int tar = target - nums[i];
            
            auto found = pastValues.find(tar);

            if (found != pastValues.end()) {
                return std::vector<int>{found->second, i};
            }

            pastValues[nums[i]] = i;
        }
        return std::vector<int>{};
    }
};
