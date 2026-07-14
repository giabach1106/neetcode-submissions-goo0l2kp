class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int x = 0, y = 0;
        string res = "";
        while (x < word1.size() and y < word2.size()) {
            res += word1[x];
            res += word2[y];
            x++;
            y++;
        }
        while (x < word1.size()) {
            res += word1[x];
            x++;
        }
        while (y < word2.size()) {
            res += word2[y];
            y++;
        }
        return res;
    }
};