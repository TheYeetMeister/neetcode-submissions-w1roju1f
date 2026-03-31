class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] ans = new int[temperatures.length];

        Stack<Integer> monotonicDecreasing = new Stack<>();

        for (int i = temperatures.length - 1; i >= 0; --i) {
            while (!monotonicDecreasing.empty()) {
                int index = monotonicDecreasing.peek();
                if (temperatures[index] > temperatures[i]) {
                    ans[i] = index - i;
                    break;
                } else {
                    monotonicDecreasing.pop();
                }
            }

            monotonicDecreasing.push(i);
        }

        return ans;
    }
}
