class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        while (l <= r) {
            int mid = (l + r) / 2;
            int mul = mid * mid;
            if (mul == x) {
                return mid;
            }
            else if (mul < x) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return l - 1;
    }
};