class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        bool a[(int)2e6];
        for (auto &i : a)
            i = false;
        for (auto i : nums) {
            i+=1e6;
            if(a[i] == 1) {
                return true;
            }
            a[i] = true;
        }
        return false;
    }
};
