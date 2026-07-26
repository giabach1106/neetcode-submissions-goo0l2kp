class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<pair<int,int>> heap;
        vector<int> res;
        int l = 0, r = 0;
        while (r < nums.size()) {
            heap.insert({nums[r], r});
            if (r - l + 1 == k) {
                res.push_back(heap.rbegin()->first);
                heap.erase({nums[l], l});
                l++;
            }
            r++;
        }
        return res;     
    }   
};
