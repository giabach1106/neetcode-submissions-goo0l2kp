class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n = nums1.size();
        int m = nums2.size();

        int l = 0;
        int r = n;

        while (l <= r) {
            int mid1 = l + (r - l) / 2;
            int mid2 = (n + m + 1) / 2 - mid1;

            int left1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int right1 = (mid1 == n) ? INT_MAX : nums1[mid1];

            int left2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int right2 = (mid2 == m) ? INT_MAX : nums2[mid2];

            if (left1 <= right2 && left2 <= right1) {
                if ((n + m) % 2 == 1) {
                    return max(left1, left2);
                }

                return (
                    static_cast<long long>(max(left1, left2)) +
                    min(right1, right2)
                ) / 2.0;
            }

            if (left1 > right2) {
                r = mid1 - 1;
            } else {
                l = mid1 + 1;
            }
        }

        return 0.0;
    }
};