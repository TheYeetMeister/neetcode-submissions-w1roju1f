class Solution {
    public int findDuplicate(int[] nums) {
        int slow = 0;
        int fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        int start = 0;

        while (start != slow) {
            start = nums[start];
            slow = nums[slow];
        }
        
        return slow;
    }
}
