class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            if (i - 1 >= 0 and intervals[i - 1][1] > intervals[i][0]) {
                intervals[i - 1][1] = max(intervals[i - 1][1], intervals[i][1]);
                res++;
                intervals.erase(intervals.begin() + i);
            }
        }
        return res;
    }
};
