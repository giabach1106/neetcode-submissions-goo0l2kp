class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            int tmp = i;
            while (tmp) {
                if (tmp & 1) 
                    res[i]++;
                tmp = tmp >> 1;
            }
        }
        return res;
    }
};
