class Solution {
public:
    void sortColors(vector<int>& nums) {
        int k = 0, j = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0 and i != k) {
                swap(nums[i], nums[k]);
                k++;
            }
            else if (nums[i] == 2 and i != j) {
                swap(nums[i], nums[j]);
                j--;
            }
            if (i >= j)
                break;
        } 
    }

};