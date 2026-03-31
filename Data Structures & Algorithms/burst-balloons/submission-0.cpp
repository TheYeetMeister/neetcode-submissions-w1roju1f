class Solution {
    int getCoins(vector<int>& nums, int k) {
        int front = 1;

        for (int i = k - 1; i >= 0; --i) {
            if (nums[i]) {
                front = nums[i];
                break;
            }
        }

        int back = 1;

        for (int i = k + 1; i < nums.size(); ++i) {
            if (nums[i]) {
                back = nums[i];
                break;
            }
        }

        return front * back * nums[k];
    }

    int dfs(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                int temp = nums[i];
                int coins = getCoins(nums, i);
                nums[i] = 0;

                res = max(res, coins + dfs(nums));

                nums[i] = temp;
            }
        }

        return res;
    }
public:
    int maxCoins(vector<int>& nums) {
        return dfs(nums);
    }
};
