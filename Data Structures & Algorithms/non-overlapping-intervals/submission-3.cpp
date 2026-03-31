class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int begin = intervals[0][0];
        int end = intervals[0][1];
        int cnt = 0;

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) {
                ++cnt;

                if (intervals[i][1] < end) {
                    begin = intervals[i][0];
                    end = intervals[i][1];
                }
            } else {
                begin = intervals[i][0];
                end = intervals[i][1];
            }
        }

        return cnt;
    }
};
