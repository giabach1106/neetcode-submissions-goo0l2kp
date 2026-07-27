class Solution {
private:
    bool check(vector<int>& weights, int days, int k) {
        int cur_total = 0;
        int days_total = 1;
        for (auto weight : weights) {
            if (cur_total + weight > k) {
                cur_total = weight;
                days_total++;
            }
            else {
                cur_total += weight;
            }
        }
        return days_total <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()), right = 0;
        for (auto weight : weights) {
            right += weight;
        }
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(weights, days, mid)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};