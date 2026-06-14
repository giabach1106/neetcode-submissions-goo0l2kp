class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            while (nums[j] == val and j - 1 >= 0) {
                j--;
            }
            if (nums[i] == val) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            else {
                i++;
            }
        }
        return i;
    }
};