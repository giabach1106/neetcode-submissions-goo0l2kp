class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num : nums)
            if (num > 0)
                s.insert(num);
        int res;
        for (int i = 1; i <= s.size() + 1; i++) 
            if (!s.count(i)) {
                res = i;
                break;
            }
        return res;
    }
};