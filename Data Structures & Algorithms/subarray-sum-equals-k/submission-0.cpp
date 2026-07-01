class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, cur = 0;
        unordered_map<int, int> presum;
        presum[0] = 1;
        for (auto num : nums) {
            cur += num;
            int diff = cur - k;
            res += presum[diff];
            presum[num]++;
        }        
        return res;
    }
};
