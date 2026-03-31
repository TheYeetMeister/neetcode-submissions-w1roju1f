class Solution {
public:
    int basicBinarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        if (nums[left] <= nums[right]) {
            return basicBinarySearch(nums, target, left, right);
        }

        int midCutOff = 0;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] < nums[midCutOff]) {
                midCutOff = mid;
            }

            //wanna keep moving towards minimum value
            if (nums[mid] < nums[right]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (nums[0] <= target) {
            return basicBinarySearch(nums, target, 0, midCutOff - 1);
        } else {
            return basicBinarySearch(nums, target, midCutOff, nums.size() - 1);
        }
    }
};
