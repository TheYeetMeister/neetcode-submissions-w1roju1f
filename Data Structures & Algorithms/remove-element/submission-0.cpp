class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int i = 0;

        while (i < size) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                --size;
            } else {
                ++i;
            }
        }

        return size;
    }
};