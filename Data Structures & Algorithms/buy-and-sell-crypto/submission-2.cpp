class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int l = 0, r = 1;
        while (r < prices.size()) {
            int profit = prices[r] - prices[l];
            if (profit < 0) {
                l = r;
                r++;
            } else {
                res = max(res, profit);
                r++;
            }
        }
        return res;
    }
};
