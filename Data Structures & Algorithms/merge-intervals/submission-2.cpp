class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 0) return res;

        sort(intervals.begin(), intervals.end());
        int begin = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > end) {
                res.push_back({begin, end});

                //set new end interval
                begin = intervals[i][0];
                end = intervals[i][1];
            } else {
                //overlapping so create new
                end = max(intervals[i][1], end);
            }
        }

        res.push_back({begin, end});

        return res;
    }
};
