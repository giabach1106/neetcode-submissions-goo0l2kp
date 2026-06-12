class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int c = target - nums[i];
            if (m.count(c)) {
                res.push_back(m[c]);
                res.push_back(i);
                break;
            }
            else {
                m[nums[i]] = i;
            }
        }
        return res;
    }
};
