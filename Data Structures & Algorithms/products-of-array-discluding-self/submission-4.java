class Solution {
    private int[] createPrefix(int[] nums) {
        int prefix[] = new int[nums.length + 1];
        prefix[0] = 1;

        for (int i = 0; i < nums.length; ++i) {
            prefix[i + 1] = nums[i] * prefix[i];
        }

        return prefix;
    }

    private int[] createPostfix(int[] nums) {
        int postfix[] = new int[nums.length + 1];
        postfix[postfix.length - 1] = 1;

        for (int i = nums.length - 1; i >= 0; --i) {
            postfix[i] = nums[i] * postfix[i + 1];
        }

        return postfix;
    }

    public int[] productExceptSelf(int[] nums) {
        int prefix[] = createPrefix(nums);
        int postfix[] = createPostfix(nums);
        int res[] = new int[nums.length];
        
        for (int i = 0; i < nums.length; ++i) {
            res[i] = prefix[i] * postfix[i + 1];
        }

        return res;
    }
}  
