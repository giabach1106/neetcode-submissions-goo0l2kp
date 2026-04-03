class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res;
        int h1, h2;
        if (nums1.size() > nums2.size())
            nums1.swap(nums2);
        int half = (nums1.size() + nums2.size()+1)/2;
        h2 = half - h1;
        int left = 0, right = nums1.size();
        while (left <= right) {
            h1 = left + (right - left)/2;
            h2 = half - h1;
            int nums1Left = (h1 > 0) ? nums1[h1 - 1] : INT_MIN;
            int nums1Right = (h1 < nums1.size()) ? nums1[h1] : INT_MAX;
            int nums2Left = (h2 > 0) ? nums2[h2 - 1] : INT_MIN;
            int nums2Right = (h2 < nums2.size()) ? nums2[h2] : INT_MAX;
            if (nums1Left > nums2Right) {
                right = h1 - 1;
            } else if (nums2Left > nums1Right) {
                left = h1 + 1;
            } else {
                if ((nums1.size() + nums2.size()) % 2 == 0) {
                    return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;
                } else {
                    return max(nums1Left, nums2Left);
                }
            } 
        }
        return res;
    }
};
