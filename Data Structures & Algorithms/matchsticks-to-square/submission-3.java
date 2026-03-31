class Solution {
    int[] lengths;
    int targetLength;
    int[] matchsticks;

    private boolean dfs(int i) {
        if (i == matchsticks.length) {
            return true;
        }

        for (int j = 0; j < lengths.length; ++j) {
            lengths[j] += matchsticks[i];

            if (lengths[j] <= targetLength && dfs(i + 1)) {
                return true;
            }

            lengths[j] -= matchsticks[i];
        }
        return false;
    }

    public boolean makesquare(int[] matchsticks) {
        this.matchsticks = matchsticks;
        int length = Arrays.stream(matchsticks).sum();

        if (length % 4 > 0) {
            return false;
        }

        targetLength = length / 4;
        lengths = new int[4];
        return dfs(0);
    }
}