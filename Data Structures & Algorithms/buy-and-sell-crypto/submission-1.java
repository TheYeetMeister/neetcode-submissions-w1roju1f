class Solution {
    public int maxProfit(int[] prices) {
        int smallestSell = prices[0];
        int res = 0;

        for (int i = 1; i < prices.length; ++i) {
            if (prices[i] < smallestSell) {
                smallestSell = prices[i];
            } else {
                res = Math.max(prices[i] - smallestSell, res);
            }
        }

        return res;
    }
}
