class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target = -1 * nums[i];
            int j = i + 1;
            int k = nums.length - 1;

            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    ++j;
                    continue;
                }

                if (nums[j] + nums[k] == target) {
                    res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                }

                if (nums[j] + nums[k] > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }

        return res;
    }
}
