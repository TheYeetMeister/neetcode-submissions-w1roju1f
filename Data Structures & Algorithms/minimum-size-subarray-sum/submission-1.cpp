class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int res = INT_MAX;
        int tempSum = 0;
        
        for (int r = 0; r < nums.size(); ++r) {
            tempSum += nums[r];

            while (tempSum >= target) {
                res = min(res, r - l + 1);
                
                tempSum -= nums[l++];
            }
        }

        return (res == INT_MAX)? 0: res;
    }
};