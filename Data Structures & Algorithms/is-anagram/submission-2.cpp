class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[260], b[260];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        
        if (s.size() != t.size())
            return false;
        for(int i  = 0; i < s.size(); i++){
            a[s[i] - 'a']++;
            b[t[i] - 'a']++;
        }
        for(int i = 0; i < 260; i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
};
