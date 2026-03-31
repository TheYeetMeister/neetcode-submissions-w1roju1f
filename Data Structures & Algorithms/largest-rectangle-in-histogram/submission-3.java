class Solution {
    private int calRect(Pair<Integer, Integer> leftInfo, int rightInd) {
        return leftInfo.getKey() * (rightInd - leftInfo.getValue());
    }

    public int largestRectangleArea(int[] heights) {
        int maxRect = 0;

        Stack<Pair<Integer, Integer>> buf = new Stack<>();

        for (int i = 0; i < heights.length; ++i) {
            if (buf.empty() || heights[i] > buf.peek().getKey()) {
                buf.push(new Pair(heights[i], i));
            } else {
                Pair<Integer, Integer> topVal = buf.pop();
                while (!buf.empty() && buf.peek().getKey() >= heights[i]) {
                    maxRect = Math.max(maxRect, calRect(topVal, i));
                    topVal = buf.pop();
                }
                
                maxRect = Math.max(maxRect, calRect(topVal, i));
                buf.push(new Pair(heights[i], topVal.getValue()));
            }
        }

        while (!buf.empty()) {
            maxRect = Math.max(maxRect, calRect(buf.pop(), heights.length));
        }

        return maxRect;
    }
}
