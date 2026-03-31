class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> daysTillHigherTemp(temperatures.size(), 0);
        stack<int> dayStack;

        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!dayStack.empty() && temperatures[dayStack.top()] <= temperatures[i]) {
                dayStack.pop();
            }

            if (!dayStack.empty()) {
                daysTillHigherTemp[i] = dayStack.top() - i;
            }
            dayStack.push(i);
        }

        return daysTillHigherTemp;
    }
};
