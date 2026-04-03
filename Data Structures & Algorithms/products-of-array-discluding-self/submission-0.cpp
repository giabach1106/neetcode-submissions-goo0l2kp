class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0, mul = 1;
        for (auto num : nums) {
            if (num == 0)
                zeros++;
            else mul *= num;
        }
        vector<int> res;
        for (auto num : nums) {
            if (zeros == 0)
                res.push_back(mul / num);
            else if (zeros == 1 and num == 0) {
                res.push_back(mul);
            }
            else {
                res.push_back(0);
            }
        }
        return res;
        
    }
};
