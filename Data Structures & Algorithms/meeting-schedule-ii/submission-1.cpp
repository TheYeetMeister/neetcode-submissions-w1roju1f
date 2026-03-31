/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a.start < b.start;
        });

        int cnt = 0;
        int days = 0;
        int lastEnd;

        while (cnt < intervals.size()) {
            lastEnd = -1;
            for (int i = 0; i < intervals.size(); ++i) {
                if (intervals[i].start >= lastEnd) {
                    lastEnd = intervals[i].end;
                    intervals[i].start = -2;
                    intervals[i].end = -2;
                    ++cnt;
                }
            }
            ++days;
        }

        return days;
    }
};
