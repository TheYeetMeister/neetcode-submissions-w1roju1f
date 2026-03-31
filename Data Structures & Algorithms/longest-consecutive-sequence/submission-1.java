class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> numSet = new HashSet<>();
        for (int num: nums) {
            numSet.add(num);
        }

        int res = 0;
        for (int num: nums) {
            if(numSet.contains(num - 1)) continue;

            int newRes = 0;
            for (int i = num; numSet.contains(i); ++i, ++newRes);

            res = Math.max(res, newRes);
        }
        return res;
    }
}
