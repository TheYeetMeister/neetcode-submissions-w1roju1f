class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() < 2) {
            return min(cost[0], cost[1]);
        }

        vector<int> minCosts(cost.size(), INT_MAX);
        minCosts[0] = cost[0];
        minCosts[1] = cost[1];

        for (int i = 2; i < cost.size(); ++i) {
            minCosts[i] = min(minCosts[i-2] + cost[i], minCosts[i]);
            minCosts[i] = min(minCosts[i-1] + cost[i], minCosts[i]);
        }

        return min(minCosts.back(), minCosts[minCosts.size() - 2]);
    }
};
