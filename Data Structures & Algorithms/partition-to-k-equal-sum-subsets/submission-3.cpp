class Solution {
    int target;
    int k;
    vector<int> nums;
    vector<bool> used;

    bool dfs(int i, int k, int subsetSum) {
        if (k == 0) {
            return true;
        } else if (subsetSum == target) {
            return dfs(0, k - 1, 0);
        }

        for (int j = i; j < nums.size(); ++j) {
            if (used[j] || subsetSum + nums[j] > target) {
                continue;
            }
            used[j] = true;
            if (dfs(j + 1, k, subsetSum + nums[j])) {
                return true;
            }
            used[j] = false;
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        used = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());

        if (sum % k > 0) {
            return false;
        }
        this->k = k;
        target = sum / k;
        this->nums = nums;

        return dfs(0, k, 0);
    }
};