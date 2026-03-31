class Solution {
    void mergedSort(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return;
        }

        int size = nums.size();
        vector<int> a(nums.begin(), nums.begin() + size / 2);
        vector<int> b(nums.begin() + size / 2, nums.end());

        mergedSort(a);
        mergedSort(b);

        int i = 0;
        int j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                nums[i + j] = a[i];
                ++i;
            } else {
                nums[i + j] = b[j];
                ++j;
            }
        }

        for (; i < a.size(); ++i) {
            nums[i + j] = a[i];
        }

        for (; j < b.size(); ++j) {
            nums[i + j] = b[j];
        }
    }
public:
    void sortColors(vector<int>& nums) {
        mergedSort(nums);      
    }
};