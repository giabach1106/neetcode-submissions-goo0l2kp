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
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a.start < b.start;
        });
        vector<Interval> rooms;
        for (auto meeting : intervals) {
            bool found = false;
            for (auto room : rooms) {
                if (room.end <= meeting.start) {
                    room.end = meeting.end;
                    found = true;
                    break;
                }
            }
            if (!found) {
                rooms.push_back(meeting);
            }
        }
        return rooms.size();
    } 
};
