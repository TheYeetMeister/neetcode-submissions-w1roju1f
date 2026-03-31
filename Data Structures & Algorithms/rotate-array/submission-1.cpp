class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        vector<int> temp;
        for (int i = 0; i < k; ++i) {
            temp.push_back(nums[n - i - 1]);
        }

        int i = n - 1;
        for (; i >= k; --i) {
            nums[i] = nums[i - k];
        }

        for (; i >= 0; --i) {
            nums[i] = temp[k - i - 1];
        }
    }
};