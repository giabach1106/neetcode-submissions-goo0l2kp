class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i <= 31; i++) {
            uint32_t mask = 1 << i;
            if (mask & n) {
                res++;
            }
        }
        return res;
    }
};
