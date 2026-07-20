class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_set<int> set1 (s1.begin(), s1.end()), set2; 
        int l = 0, r = 0;
        while (r < s2.size()) {
            if (set1 == set2)   
                return true;
            if (r - l + 1 > s1.size()) {
                set2.erase(s2[l]);
                l++;
            }
            set2.insert(s2[r]);
            r++;
        }
        // dcda
        // d
        return false;
    }
};
