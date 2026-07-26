class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool res = false;
        int row = matrix.size(), col = matrix[0].size();
        int l = 0, r = row * col - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int cur = matrix[m / col][m % col];
            cout << l << " " << r << " " << cur << endl;
            if (cur == target) {
                res = true;
                break;
            }
            else if (cur < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return res;
    }
};
