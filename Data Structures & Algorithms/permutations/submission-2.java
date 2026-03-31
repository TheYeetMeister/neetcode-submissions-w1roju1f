class Solution {
    List<List<Integer>> res;
    List<Integer> subset;
    List<Boolean> pickList;
    int[] nums;

    private void dfs() {
        if (subset.size() == nums.length) {
            res.add(new ArrayList<>(subset));
            return;
        }

        for (int i = 0; i < nums.length; ++i) {
            if (pickList.get(i)) {
                pickList.set(i, false);
                subset.add(nums[i]);
                dfs();
                subset.remove(subset.size() - 1);
                pickList.set(i, true);
            }
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        this.nums = nums;
        res = new ArrayList<>();
        subset = new ArrayList<>();
        pickList = new ArrayList<>(nums.length);

        for (int i = 0; i < nums.length; ++i) {
            pickList.add(true);
        }

        dfs();

        return res;
    }
}
