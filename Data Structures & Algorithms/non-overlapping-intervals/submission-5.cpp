class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (i - 1 >= 0 and intervals[i - 1][1] > intervals[i][0]) {
                res++;
                intervals.erase(intervals.begin() + i);
                i--;
            }
        }

        return res;
    }
};
