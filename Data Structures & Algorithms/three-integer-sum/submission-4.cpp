class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threeSums{};

        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        for (int i = 0; i < sortedNums.size() - 2; ++i) {
            if (i > 0 && sortedNums[i - 1] == sortedNums[i]) {
                continue;
            }

            int left = i + 1;
            int right = sortedNums.size() - 1;

            while (left < right) {
                int sum = sortedNums[i] + sortedNums[left] + sortedNums[right];
                if (sum > 0) {
                    --right;
                }  else if (sum < 0) {
                    ++left;
                } else {
                    threeSums.push_back(vector<int>{sortedNums[i], sortedNums[left], sortedNums[right]});
                    --right;
                    for(; sortedNums[right] == sortedNums[right + 1]; --right);
                }
            }
        }

        return threeSums;
    }
};
