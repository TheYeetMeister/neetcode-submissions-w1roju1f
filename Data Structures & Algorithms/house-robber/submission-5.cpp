class Solution {
public:
    //tautology either rob a house and jump two, or don't rob a house and rob the one after it
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> moneyMade(nums.size() + 1, 0);

        moneyMade[1] = nums[0];
        moneyMade[2] = nums[1];


        for (int i = 3; i < moneyMade.size(); ++i) {
            moneyMade[i] = max(moneyMade[i - 3], moneyMade[i - 2]);
            moneyMade[i] += nums[i - 1];
        }

        return max(moneyMade.back(), moneyMade[moneyMade.size() - 2]);
    }

    //recurssive solution
    int findMax(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }

        int take = nums[i] + findMax(nums, i + 2);

        int dontTake = findMax(nums, i + 1);

        return max(take, dontTake);
    }
};
