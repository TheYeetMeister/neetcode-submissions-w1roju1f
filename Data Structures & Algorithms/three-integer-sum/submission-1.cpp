class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threeSums{};

        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        int prev = INT_MIN;
        for (int i = 0; i < sortedNums.size() - 2; ++i) {
            for (; sortedNums[i] == prev; ++i);
            prev = sortedNums[i];

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
                    for(int rightPrev = sortedNums[right]; rightPrev == sortedNums[right]; --right);
                }
            }
        }

        return threeSums;
    }
};
