class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int min = INT_MAX, max = INT_MIN;
        for (auto num : nums) {
            if (min > num)
                min = num;
            if (max < num) 
                max = num;
        }
        unordered_set<int> s(nums.begin(), nums.end());
        for (auto x : s)
            cout << x << " ";
        for (int i = min; i <= max; i++) {
            if (!s.count(i) and i > 0) 
                return i;
        }
        return max + 1;
    }
};