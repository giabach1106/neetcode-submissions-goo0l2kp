class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size() - 1;
        while (n > 0 and m > 0) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[i] = nums1[m - 1];
                m--;
            }
            else {
                nums1[i] = nums2[n - 1];
                n--;
            }
            i--;
        }
        for (int j = 0; j < n; j++) {
            nums1[j] = nums2[j];
        }
    }
};