class Solution {
    bool isNumMajority(const vector<int>& nums, int candidate) {
        int threshHold = nums.size() / 3;
        int count = 0;

        for (int i: nums) {
            if (i == candidate) {
                ++count;
            }
        }

        return count > threshHold;
    }
public:
    vector<int> majorityElement(vector<int>& nums) {
        int firstCan = 0;
        int secondCan = 0;

        int firstCanCount = 0;
        int secondCanCount = 0;

        for (int i: nums) {
            if (firstCanCount == 0) {
                firstCan = i;
                ++firstCanCount;
            } else if (firstCan == i) {
                ++firstCanCount;
            } else if (secondCanCount == 0) {
                secondCan = i;
                ++secondCanCount;
            } else if (secondCan == i) {
                ++secondCanCount;
            } else {
                --firstCanCount;
                --secondCanCount;
            }
        }

        vector<int> res;
        if (isNumMajority(nums, firstCan)) {
            res.push_back(firstCan);
        }
        if (isNumMajority(nums, secondCan)) {
            res.push_back(secondCan);
        }

        return res;
    }
};