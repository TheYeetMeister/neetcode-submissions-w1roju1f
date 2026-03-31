class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //index, size
        stack<pair<int, int>> monotonicIncreasingHeight;

        int maxSize = 0;

        for (int i = 0; i < heights.size(); ++i) {
            if (!monotonicIncreasingHeight.empty()) {
                pair<int, int> currEarliestWidth = monotonicIncreasingHeight.top();
                monotonicIncreasingHeight.pop();

                while (!monotonicIncreasingHeight.empty() && monotonicIncreasingHeight.top().second >= heights[i]) {
                    currEarliestWidth = monotonicIncreasingHeight.top();
                    maxSize = max(maxSize, (i - currEarliestWidth.first) 
                                    * min(currEarliestWidth.second, heights[i - 1]));
                    monotonicIncreasingHeight.pop();
                }

                if (currEarliestWidth.second >= heights[i]) {
                    currEarliestWidth.second = heights[i];
                }

                monotonicIncreasingHeight.push(currEarliestWidth);
            }

            monotonicIncreasingHeight.push(make_pair(i, heights[i]));

            maxSize = max(maxSize, heights[i]);
        }

        while (!monotonicIncreasingHeight.empty()) {
            maxSize = max(maxSize, (int(heights.size()) - monotonicIncreasingHeight.top().first) 
                                    * monotonicIncreasingHeight.top().second);
            monotonicIncreasingHeight.pop();
        }

        return maxSize;
    }
};
