class Solution {
    List<List<Integer>> res;
    List<Integer> subset;

    private void dfs(int[] nums, int i) {
        if (i == nums.length) {
            res.add(new ArrayList<Integer>(subset));
            return;
        }

        subset.add(nums[i]);
        dfs(nums, i + 1);
        subset.remove(subset.size() - 1);

        dfs(nums, i + 1);
    }

    public List<List<Integer>> subsets(int[] nums) {
        res = new ArrayList<>();
        subset = new ArrayList<>();

        dfs(nums, 0);

        return res;
    }
}
