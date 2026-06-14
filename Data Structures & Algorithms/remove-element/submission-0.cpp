class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        vector<int> tmp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                res++;
                tmp.push_back(nums[i]);
            }
        }
        for (int i = 0; i < res; i++) {
            nums[i] = tmp[i];
        }
        return res;
    }
};