class Solution {
    List<List<Integer>> res;
    List<Integer> subset;
    int[] nums;

    private void dfs(int i) {
        if (i == nums.length) {
            return;
        }

        subset.add(nums[i]);
        res.add(new ArrayList<>(subset));
        dfs(i + 1);
        subset.remove(subset.size() - 1);

        while (i + 1 < nums.length && nums[i] == nums[i + 1]) {
            ++i;
        }
        dfs(i + 1);
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        res = new ArrayList<>();
        res.add(new ArrayList<>());
        subset = new ArrayList<>();
        this.nums = nums;
        Arrays.sort(nums);

        dfs(0);

        return res;
    }
}
