class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int cur = 0;
        // 2 3 4 4 5 10 20
        if (nums.size() == 0)
            return 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i - 1 >= 0) {
                if (nums[i] - nums[i - 1] == 1) {
                    cur++;
                    res = max(res, cur);
                }
                else if (nums[i] - nums[i - 1] == 0)
                    continue;
                else cur = 0;
                cout << nums[i] << " " << cur << endl;
            }
        }
        return res + 1;
    }
};
