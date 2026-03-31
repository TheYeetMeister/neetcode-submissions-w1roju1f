class Solution {
    private int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }

    public int search(int[] nums, int target) {
        int start = findMin(nums);

        System.out.println(start);

        int l = 0, r = nums.length - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            int index = (mid + start < nums.length) ? mid + start: mid - (nums.length - start);

            if (nums[index] < target) {
                l = mid + 1;
            } else if (nums[index] > target) {
                r = mid - 1;
            } else {
                return index;
            }
        }

        return -1;
    }
}
