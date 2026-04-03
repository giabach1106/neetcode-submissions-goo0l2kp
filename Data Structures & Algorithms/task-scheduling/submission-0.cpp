class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0;
        vector<int> counts (26, 0);
        priority_queue<int> maxHeap;
        queue<pair<int,int>> q;
        for (char task : tasks) {
            counts[task - 'A']++;
        }
        for (auto count : counts) {
            if (count > 0) {
                maxHeap.push(count);
            }
        }
        while (!maxHeap.empty() || !q.empty()) {
            res++;
            if (maxHeap.empty()) {
                res = q.front().second;
            } else {
                int tmp = maxHeap.top() - 1;
                maxHeap.pop();
                if (tmp > 0) {
                    q.push({tmp, res + n});
                }
            }
            if (!q.empty() && q.front().second == res) {
                maxHeap.push(q.front().first);
                q.pop();
            }

        }
        return res;
    }
};
