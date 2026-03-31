class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) {
            return false;
        }

        unordered_set<int> freqSet;

        for (int i = 0; i < k && i < nums.size(); ++i) {
            if (freqSet.find(nums[i]) != freqSet.end()) {
                return true;
            }

            freqSet.insert(nums[i]);
        }

        for (int i = k; i < nums.size(); ++i) {
            if (freqSet.find(nums[i]) != freqSet.end()) {
                return true;
            }

            freqSet.insert(nums[i]);
            freqSet.erase(nums[i - k]);
        }

        return false;
    }
};