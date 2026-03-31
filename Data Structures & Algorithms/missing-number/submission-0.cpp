class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res += i + 1;
            ans += nums[i];
        }

        return res - ans;
    }
};
