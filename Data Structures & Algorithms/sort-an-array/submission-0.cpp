class Solution {
    void mergedSort(vector<int>& nums) {
        int size = nums.size();

        if (size == 0 || size == 1) {
            return;
        }

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
    vector<int> sortArray(vector<int>& nums) {
        mergedSort(nums);

        return nums;
    }
};