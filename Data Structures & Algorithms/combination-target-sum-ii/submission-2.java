class Solution {
    List<List<Integer>> res;
    List<Integer> subset;

    private void dfs(int i, int currsum, int[] candidates, int target) {
        if (currsum == target) {
            res.add(new ArrayList<>(subset));
            return;
        }

        if (i == candidates.length || currsum > target) {
            return;
        }

        int nextI = i + 1;
        while (nextI < candidates.length && candidates[i] == candidates[nextI]) {
            ++nextI;
        }

        dfs(nextI, currsum, candidates, target);
        for (int j = i; j < nextI; ++j) {
            currsum += candidates[i];
            subset.add(candidates[i]);
            dfs(nextI, currsum, candidates, target);
        }

        for (int j = i; j < nextI; ++j) {
            subset.remove(subset.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);

        res = new ArrayList<>();
        subset = new ArrayList<>();

        dfs(0, 0, candidates, target);

        return res;
    }
}
