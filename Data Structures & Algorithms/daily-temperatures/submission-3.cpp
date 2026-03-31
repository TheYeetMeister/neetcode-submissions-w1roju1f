class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        unsigned n = temperatures.size();
        vector<int> daysTillHigherTemp(temperatures.size(), 0);

        for (int i = n - 2; i >= 0; --i) {
            int j = i + 1;
            while (j < n && temperatures[j] <= temperatures[i]) {
                if (!daysTillHigherTemp[j]) {
                    j = n;
                    break;
                }
                j += daysTillHigherTemp[j];
            }

            if (j < n) {
                daysTillHigherTemp[i] = j - i;
            }
        }

        return daysTillHigherTemp;
    }
};
