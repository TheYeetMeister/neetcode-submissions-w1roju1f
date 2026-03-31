class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) {
            return false;
        }

        unordered_map<int, int> freqList;

        for (int i = 0; i < k && i < nums.size(); ++i) {
            if (freqList[nums[i]]) {
                return true;
            }

            ++freqList[nums[i]];
        }

        for (int i = k; i < nums.size(); ++i) {
            if (freqList[nums[i]]) {
                return true;
            }

            ++freqList[nums[i]];
            --freqList[nums[i - k]];
        }

        return false;
    }
};