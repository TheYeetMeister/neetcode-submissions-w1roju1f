class Solution {
    public boolean hasDuplicate(int[] nums) {
        Set<Integer> vals = new HashSet<>();

        for (int i: nums) {
            if (vals.contains(i)) return true;

            vals.add(i);
        }
        return false;
    }
}