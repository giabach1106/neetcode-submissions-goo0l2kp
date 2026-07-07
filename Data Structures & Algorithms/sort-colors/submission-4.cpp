class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (auto num : nums) {
            if (num == 0) cnt0++;
            if (num == 1) cnt1++;
            if (num == 2) cnt2++;
        }
        for (int i = 0; i < cnt0; i++) {
            nums[i] = 0;
        }
        for (int i = 0; i < cnt1; i++) {
            nums[i + cnt0] = 1;
        }
        for (int i = 0; i < cnt2; i++) {
            nums[i + cnt0 + cnt1] = 2;
        }
            
    }
};