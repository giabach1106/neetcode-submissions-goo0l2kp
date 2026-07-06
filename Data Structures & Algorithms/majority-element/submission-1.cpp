class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n % 2 == 1)
            n = n /2 + 1;
        else n = n /2;
        unordered_map<int, int> m;
        int res = 0;
        for (auto num : nums) {
            m[num]++;
            if (m[num] >= n) {
                res = num;
                break;
            }
        } 
        return res;
    }
};