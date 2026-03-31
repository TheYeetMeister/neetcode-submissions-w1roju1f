#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numsSet;

        for (int i: nums) {
            if (numsSet.find(i) != numsSet.end()) {
                return true;
            }
            numsSet.insert(i);
        }

        return false;
    }
};
