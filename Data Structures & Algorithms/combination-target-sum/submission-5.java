class Solution {
    List<Integer> subset;
    List<List<Integer>> res;
    private void dfs(int i, int currSum, int[] nums, int target) {
        if (currSum == target) {
            res.add(new ArrayList<>(subset));
            return;
        }

        if (i == nums.length || currSum > target) {
            return;
        }

        int count = 0;

        while (currSum <= target) {
            dfs(i + 1, currSum, nums, target);
            currSum += nums[i];
            subset.add(nums[i]);
            ++count;
        }

        for (int k = 0; k < count; ++k) {
            subset.remove(subset.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum(int[] nums, int target) {
        Arrays.sort(nums);
        subset = new ArrayList<>();
        res = new ArrayList<>();

        dfs(0, 0, nums, target);

        return res;
    }
}
