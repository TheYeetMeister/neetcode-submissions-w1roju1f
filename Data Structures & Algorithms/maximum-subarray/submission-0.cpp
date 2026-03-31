class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int curr = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            curr += nums[i];

            if (curr < nums[i]) {
                curr = nums[i];
            }

            if (curr > res) {
                res = curr;
            }
        }

        if (curr > res) {
            res = curr;
        }

        return res;
    }
};
