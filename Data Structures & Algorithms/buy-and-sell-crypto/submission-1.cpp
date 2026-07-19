class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int res = 0;
        while (r < prices.size()) {
            if (prices[r] > prices[l]) {
                res = max(res, prices[r] - prices[l]);
                r++;
            }
            else {
                r++;
                l++;
            }
        }
        
        return res;
    }
};
