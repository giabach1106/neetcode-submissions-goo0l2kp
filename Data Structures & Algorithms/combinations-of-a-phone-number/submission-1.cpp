class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits == "") {
            return res;
        }
        vector<string> A = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string str = "";
        dfs(res, str, digits, A, 0);
        return res;
    }
private:
    void dfs(vector<string>& res, string str, string digits, vector<string>& A, int n) {
        if (str.size() == digits.size()) {
            res.push_back(str);
            return;
        }
        string s = A[digits[n] - '0'];
        for (auto c : s) {
            dfs(res, str + c, digits, A, n + 1);
        }
    }
};
