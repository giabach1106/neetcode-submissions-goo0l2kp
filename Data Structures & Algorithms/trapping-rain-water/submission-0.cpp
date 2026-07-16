class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> pre (height.begin(), height.end());
        vector<int> pos (height.begin(), height.end());
        for (int i = 0; i < pre.size(); i++) {
            if (i - 1 >= 0)
                pre[i] = max(pre[i], pre[i - 1]);
        }
        for (int i = height.size() - 1; i >= 0; i--) {
            if (i + 1 < height.size()) 
                pos[i] = max(pos[i], pos[i + 1]);
        }
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            res += min(pre[i], pos[i]) - height[i];
        }

        return res;
    }
};
