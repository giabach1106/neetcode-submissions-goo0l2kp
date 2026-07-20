class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m1, m2;
        for (auto c : s1) {
            m1[c]++;
        } 
        int l = 0, r = 0;
        while (r < s2.size()) {
            if (r - l + 1 > s1.size()) {
                m2[s2[l]]--;
                if (m2[s2[l]] == 0)
                    m2.erase(s2[l]);
                l++;
            }
            m2[s2[r]]++;
            if (m1 == m2)
                return true;
            r++;
        }
        return false;
    }
};
