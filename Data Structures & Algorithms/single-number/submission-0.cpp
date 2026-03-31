class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int value = 0;

        for (int i: nums) {
            value ^= i;
        }

        return value;
    }
};
