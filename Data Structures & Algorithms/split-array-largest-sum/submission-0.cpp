class Solution {
private:
    bool check(vector<int>& nums, int k, int max_possible) {
        int count = 1;
        int tmp_sum = 0;
        for (auto num : nums) {
            if (tmp_sum + num > max_possible) {
                tmp_sum = num;
                count++;
            }
            else {
                tmp_sum += num;
            }
        }
        return count <= k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int r = 0;
        int l = INT_MIN;
        int res = 0;
        for (auto num : nums) {
            r += num;
            l = max(l, num);
        }
        while (l <= r) {
            int m = (l + r) / 2;
            if (check(nums, k, m)) {
                r = m - 1;
            }
            else l = m + 1;
        }
        return l;
    }
};