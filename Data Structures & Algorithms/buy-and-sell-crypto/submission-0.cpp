class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        vector<int> mmin(prices.begin(), prices.end());
        vector<int> mmax(prices.begin(), prices.end());
        for (int i = 1; i < mmin.size(); i++) {
            mmin[i] = min(mmin[i], mmin[i - 1]);
        }
        for (int i = mmax.size() - 2; i >= 0; i--) {
            mmax[i] = max(mmax[i], mmax[i + 1]);
        }
        for (int i = 0; i < prices.size(); i++) {
            res = max(res, mmax[i] - mmin[i]);
        }
        return res;
    }
};
