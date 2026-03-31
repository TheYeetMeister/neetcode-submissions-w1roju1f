class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> frequencyCount;

        for (int i: nums) {
            ++frequencyCount[i];
        }
        
        int val = -1;
        int count = -1;
        for (auto i: frequencyCount) {
            if (i.second > count) {
                val = i.first;
                count = i.second;
            }
        }
        return val;
    }
};