class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> check1, check2;
        for (auto i : s1)
            check1[i]++;
        int left = 0;
        for (int right = 0; right < s2.size(); right++) {
            check2[s2[right]]++;
            if (right >= s1.size()) {
                check2[s2[left]]--;
                if (check2[s2[left]] == 0)
                    check2.erase(s2[left]);
                left++;
            }
            if (check1 == check2)
                return true;
        }  
        return false;
    }
};
