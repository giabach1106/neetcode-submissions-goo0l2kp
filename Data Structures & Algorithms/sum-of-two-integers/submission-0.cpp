class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;
        for (int i = 0; i < 32; i++) {
            int tmpa = a & 1;
            int tmpb = b & 1;
            a = a >> 1;
            b = b >> 1;
            res = res | ((tmpa ^ tmpb ^ carry) << i);
            carry = (tmpa & tmpb) | (carry & tmpa) | (carry & tmpb);
        }
        return res;
    }
};
