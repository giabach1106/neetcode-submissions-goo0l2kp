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
        // (0, 50), (10, 15), (15, 20)
        // -----------------------------------
        // 0                                 50
        //      --------- -------
        //      10      15       20
        vector<int> start, end;
        for (auto tmp : intervals) {
            start.push_back(tmp.start);
            end.push_back(tmp.end);
        }     
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i = 0, j = 0, count = 0, res = 0;
        while (i < intervals.size()) {
            if (start[i] < end[j]) {
                i++;
                count++;
            }
            else { // start[i] >= end[j]
                j++;
                count--;
            }
            res = max(res, count);
        }
        return res;
    } 
};
