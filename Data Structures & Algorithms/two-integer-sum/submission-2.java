class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] returnList = new int[2];
        Map<Integer, Integer> visitedValues = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; ++i) {
            int targetValue = target - nums[i];

            if (visitedValues.containsKey(targetValue)) {
                returnList[0] = visitedValues.get(targetValue);
                returnList[1] = i;
                break;
            }

            visitedValues.put(nums[i], i);
        }

        return returnList;
    }
}
