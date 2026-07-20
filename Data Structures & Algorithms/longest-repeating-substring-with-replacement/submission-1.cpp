class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int l = 0, r = 0;
        unordered_map<char, int> m; 
        int maxc = 0;
        while (r < s.size()) {
            m[s[r]]++;
            maxc = max(maxc, m[s[r]]);    
            while (r - l + 1 - maxc > k) {
                m[s[l]]--;
                l++; 
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};