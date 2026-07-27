class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > nums[right]) {
                if (target < nums[left] or nums[mid] < target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            else {
                if (target < nums[mid] or target > nums[right]) {
                    right = mid - 1;
                }
                else {
                    left = right + 1;
                }
            }
        }
        return -1;
    }
};
