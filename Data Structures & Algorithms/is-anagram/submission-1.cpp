class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> a,b;
        if(s.size() != t.size())
            return false;
        for(int i = 0; i < s.size();i++){
            a[s[i]]++;
            b[t[i]]++;
        }
        for(auto [i,v] : a){
            if (a[i] != b[i])
                return false; 
        }
        return true;
    }
};
