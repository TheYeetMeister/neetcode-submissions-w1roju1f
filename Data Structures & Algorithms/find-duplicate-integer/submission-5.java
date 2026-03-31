class Solution {
    public int findDuplicate(int[] nums) {
        HashSet<Integer> dups = new HashSet<>();

        for (int i: nums) {
            if (dups.contains(i)) {
                return i;
            }

            dups.add(i);
        }

        return -1;
    }
}
