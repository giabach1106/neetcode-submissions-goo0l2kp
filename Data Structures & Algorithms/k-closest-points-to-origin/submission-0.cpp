class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, pair<int,int>>> maxHeap;
        for (auto point : points) {
            int tmp = point[0]*point[0] + point[1]*point[1];
            maxHeap.push({tmp, {point[0], point[1]}});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        while (k--) {
            res.push_back({maxHeap.top().second.first,
                           maxHeap.top().second.second});
            maxHeap.pop();
        }
        return res;
    }
};
