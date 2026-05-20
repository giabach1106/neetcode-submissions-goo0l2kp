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
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a.end < b.end;
        });
        int res = 0;
        for (int i = 0; i < intervals.size (); i++) {
            if (i - 1 >= 0 and intervals[i - 1].end > intervals[i].start) {
                res++;
                intervals.erase(intervals.begin() + i);
                i--;
            }
        }
        return res + 1;
    }
};
