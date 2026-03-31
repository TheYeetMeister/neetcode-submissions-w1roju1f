class Solution {
    int total;
    void backtracking(vector<int>& nums, int i, int currCnt) {
        if (nums.size() == i) {
            total += currCnt;
            return;
        }

        backtracking(nums, i + 1, currCnt ^ nums[i]);
        backtracking(nums, i + 1, currCnt);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        total = 0;
        backtracking(nums, 0, 0);
        return total;
    }
};