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
        int res = 0;
        vector<int> start, end;
        for (auto tmp : intervals) {
            start.push_back(tmp.start);
            end.push_back(tmp.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i = 0, count = 0, j = 0;
        while (i < intervals.size()) {
            if (start[i] < end[j]) {
                count++;
                i++;
            }
            else {
                count--;
                j++;
            }
            res = max(res, count);
        }
        return res;
    }
};
