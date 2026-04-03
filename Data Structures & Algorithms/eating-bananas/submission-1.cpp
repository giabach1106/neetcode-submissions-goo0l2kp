class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        sort(piles.begin(), piles.end());
        int right = piles[piles.size()-1];
        int res = right;
        while (left <= right) {
            int mid = left + (right-left)/2;
            long long tmp = 0;
            for (auto i : piles) {
                tmp += i % mid == 0 ? i/mid : i/mid+1; 
            }
            if (tmp <= h) {
                res = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return res;

    }
};
