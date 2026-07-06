class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> res(nums.begin(), nums.end());
        sort(res.begin(), res.end());
        return res;
    }
};