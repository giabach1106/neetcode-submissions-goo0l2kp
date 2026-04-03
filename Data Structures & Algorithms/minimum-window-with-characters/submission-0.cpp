class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> check1, check2;

        for (auto c : t)
            check1[c]++;

        int left = 0, minf = INT_MAX, matches = 0, minL = 0;

        for (int right = 0; right < s.size(); right++) {
            check2[s[right]]++;
            if (check1.count(s[right]) && check2[s[right]] == check1[s[right]])
                matches++;
            while (matches == check1.size()) {
                if (right - left + 1 < minf) {
                    minf = right - left + 1;
                    minL = left;
                }
                check2[s[left]]--;
                if (check1.count(s[left]) && check2[s[left]] < check1[s[left]])
                    matches--;
                left++;
            }
        }

        return minf == INT_MAX ? "" : s.substr(minL, minf);
    }
};
