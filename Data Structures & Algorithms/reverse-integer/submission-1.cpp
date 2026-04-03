class Solution {
public:
    int reverse(int x) {
        bool pos = x < 0 ? true : false;
        x = abs(x);
        long long res = 0;
        while (x > 0) {
            res *= 10;
            res = res + x % 10;
            x = x / 10;
        }
        res = pos ? res * -1 : res;
        return res > INT_MAX or res < INT_MIN ? 0 : res;
    }
};
