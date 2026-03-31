class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int j = 0;
        for (; i < nums.size() && i <= j; ++i) {
            if (nums[i] + i > j) {
                j = nums[i] + i;
            }
        }

        return i == nums.size();
    }
};
