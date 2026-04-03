class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0;
        vector<int> counts (26, 0);
        for (auto task : tasks) {
            counts[task - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (auto count : counts) {
            if (count > 0) {
                maxHeap.push(count);
            }
        }

        queue<pair<int, int>> q;
        while (!q.empty() || !maxHeap.empty()) {
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
