class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int start = 0, end = 0;
        for (auto tmp : intervals) {
            start = min(start, tmp[0]);
            end = max(end, tmp[1]);
        }
        vector<vector<int>> A(10010);
        for (int i = start; i <= end; i++) {
            for (auto tmp : intervals) {
                if (i >= tmp[0] and i <= tmp[1]) {
                    A[i].push_back(tmp[1] - tmp[0] + 1);
                }
            }
        }
        vector<int> res;
        for (auto q : queries) {
            if (A[q].size() == 0)
                res.push_back(-1);
            else {
                sort(A[q].begin(), A[q].end());
                res.push_back(A[q][0]);
            }
        }
        return res;
    }
};
