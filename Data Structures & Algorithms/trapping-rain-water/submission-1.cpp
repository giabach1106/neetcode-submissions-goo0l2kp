class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        vector<int> pre (height.begin(), height.end());
        vector<int> pos (height.begin(), height.end());
        for (int i = 1; i < pre.size(); i++) {
            pre[i] = max(pre[i - 1], pre[i]);
        }
        for (int i = pos.size() - 2; i >= 0; i--) {
            pos[i] = max(pos[i + 1], pos[i]);
        }
        for (int i = 0; i < height.size(); i++) {
            res += min(pos[i], pre[i]) - height[i];
        }
        return res;
    }
};
