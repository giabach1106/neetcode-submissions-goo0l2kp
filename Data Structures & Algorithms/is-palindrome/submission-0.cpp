class Solution {
public:
    bool isPalindrome(string s) {
        string ss = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' and s[i] <= 'Z')
                s[i] += 32;
            if ((s[i] >= '0' and s[i] <= '9') or (s[i] >= 'a' and s[i] <= 'z')) ss += s[i];
        }
        cout << ss;
        int left = 0, right = ss.size()-1;
        while (left < right) {
            if (ss[left] == ss[right]) {
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }
};