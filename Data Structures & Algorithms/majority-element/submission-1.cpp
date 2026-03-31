class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = -1;
        int count = 0;

        for (int i: nums) {
            if (count == 0) {
                val = i;
            }
            
            if (i == val) {
                ++count;
            } else {
                --count;
            }
        }

        return val;
    }
};