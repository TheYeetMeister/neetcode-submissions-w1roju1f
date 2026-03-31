class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int m = j + 1, n = nums.size() - 1;
                long currTarget = target - static_cast<long>(nums[i]) - static_cast<long>(nums[j]);

                while (m < n) {
                    if (nums[m] + nums[n] > currTarget) {
                        --n;
                    } else if (nums[m] + nums[n] < currTarget) {
                        ++m;
                    } else {
                        res.push_back({nums[i], nums[j], nums[m], nums[n]});

                        ++m;
                        --n;

                        while (m < n && nums[m] == nums[m - 1]) {
                            ++m;
                        }
                    }
                }
            }
        }

        return res;
    }
};