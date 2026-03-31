class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currSum = gas[0] - cost[0];
        int sumGasCost = gas[0] - cost[0];

        int result = 0;
        for (int i = 1; i < gas.size(); ++i) {
            if (currSum < 0) {
                currSum = 0;
                result = i;
            }

            currSum += gas[i] - cost[i];
            sumGasCost += gas[i] - cost[i];
        }

        if (sumGasCost < 0) {
            return -1;
        }
        
        return result;
    }
};
