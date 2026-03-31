class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0;

        while (nums[i] < 1) {
            ++i;
        }

        int missingPositive = 1;

        while (i < nums.size() && missingPositive == nums[i]) {
            while (nums[i] == missingPositive) {
                ++i;
            }
            ++missingPositive;
        }

        return missingPositive;
    }
};