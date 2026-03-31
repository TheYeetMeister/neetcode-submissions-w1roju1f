class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> positiveValues;

        for (int i: nums) {
            if (i > 0) {
                positiveValues.insert(i);
            }
        }

        int missingPositive = 1;

        while (positiveValues.find(missingPositive) != positiveValues.end()) {
            ++missingPositive;
        }

        return missingPositive;
    }
};