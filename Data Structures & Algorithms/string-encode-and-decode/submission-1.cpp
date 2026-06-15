class Solution {
public:

    string encode(vector<string>& strs) {
        string res = {};
        for (auto str : strs) {
            res += to_string(str.size()) + "#" + str;
        }
        cout << res << endl;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') 
                j++;
            int size = stoi(s.substr(i, j - i + 1));
            cout << size << endl;
            i = j + 1;
            string ss = s.substr(i, size);
            cout << ss << endl;
            res.push_back(ss);
            i += size;
        }       
        return res;
    }
};
