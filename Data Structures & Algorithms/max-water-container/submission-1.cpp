class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int l = 0, r = heights.size() - 1;
        while (l < r) {
            int mul = min(heights[l], heights[r]) * (r - l);
            res = max(res, mul);
            if (heights[l] < heights[r]) 
                l++;
            else r--;
        }

        return res;
    }
};
