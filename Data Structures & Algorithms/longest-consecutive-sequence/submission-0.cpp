class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers;

        for (int num: nums) {
            numbers.insert(num);
        }

        int maxCon = 0;
        for (int num: nums) {
            if (numbers.find(num - 1) == numbers.end()) {
                int count = 1;

                for (int currNum = num + 1; numbers.find(currNum) != numbers.end(); ++currNum, ++count);

                maxCon = max(count, maxCon);
            }
        }

        return maxCon;
    }
};
