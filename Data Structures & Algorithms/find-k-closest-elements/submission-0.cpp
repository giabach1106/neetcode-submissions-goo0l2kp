class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (abs(x - arr[i]) < abs(x - arr[idx])) {
                idx = i;
            }
        }
        vector<int> res;
        int l = idx - 1, r = idx + 1;
        res.push_back(arr[idx]);
        while (res.size() < k) {
            if (l >= 0 and r < arr.size()) {
                if (abs(x - arr[l]) <= abs(x - arr[r])) {
                    res.push_back(arr[l]);
                    l--;
                }
                else {
                    res.push_back(arr[r]);
                    r++;
                }
            }
            else if (r < arr.size()) {
                res.push_back(arr[r]);
                r++;
            }
            else if (l >= 0) {
                res.push_back(arr[l]);
                l--;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};