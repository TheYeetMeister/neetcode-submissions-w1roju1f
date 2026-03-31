class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for (int i = 0; i < k; ++i) {
            for (int j = nums.size() - 1; j >= 1; --j) {
                swap(nums[j], nums[j - 1]);
            }
        }
    }
};