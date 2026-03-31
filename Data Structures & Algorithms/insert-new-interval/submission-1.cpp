class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int i = 0;
        for (;i < intervals.size() && intervals[i][1] < newInterval[0]; ++i) {
            res.push_back(intervals[i]);
        }

        if (intervals.size() == i) {
            res.push_back(newInterval);
            return res;
        }

        if (intervals[i][0] > newInterval[1]) {
            res.push_back(newInterval);
        } else {
            //create new overlap
            int begin = min(intervals[i][0], newInterval[0]);
            int end = max(intervals[i][1], newInterval[1]);

            for (;i < intervals.size() && intervals[i][0] <= end; ++i) {
                end = max(end, intervals[i][1]);
            }

            res.push_back({begin, end});
        }

        for (;i < intervals.size(); ++i) {
            res.push_back(intervals[i]);
        }
        

        return res;
    }
};
