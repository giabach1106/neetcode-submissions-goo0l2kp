class Solution {
private:
    bool check(vector<int>& piles, int h, int k) {
        int total_hour = 0;
        for (auto pile : piles) {
            if (pile % k == 0) {
                total_hour += pile / k;
            }
            else {
                total_hour += pile / k + 1;
            }
        }
        if (total_hour <= h)
            return true;
        else return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = 0, left = 1;
        for (auto pile : piles)
            right += pile;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(piles, h, mid)) {
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return left;
    }
};
