class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre (nums.size());
        vector<int> post (nums.size());
        vector<int> res (nums.size(), 1);
        pre[0] = nums[0];
        post[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = 0; i < nums.size(); i++) {
            if (i - 1 >= 0) 
                pre[i] = nums[i] * pre[i - 1];
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + 1 < nums.size()) {
                post[i] = post[i + 1] * nums[i];
            }
        }
        cout << endl;
        for (int i = 0; i < nums.size(); i++) {
            if (i - 1 >= 0) 
                res[i] *= pre[i - 1];
            if (i + 1 < nums.size())
                res[i] *= post[i + 1];
        }
        return res;
    }
};
