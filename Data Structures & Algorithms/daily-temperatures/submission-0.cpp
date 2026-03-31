class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> daysTillHigherTemp(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            for (int j = i + 1; j < temperatures.size(); ++j) {
                if (temperatures[j] > temperatures[i]) {
                    daysTillHigherTemp[i] = j - i;
                    break;
                }
            }
        }

        return daysTillHigherTemp;
    }
};
