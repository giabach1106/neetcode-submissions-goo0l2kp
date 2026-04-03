class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& str : strs) {
            encoded += to_string(str.size()) + "#" + str;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        
        while (i < s.size()) {
            // Find the delimiter '#'
            size_t pos = s.find('#', i);
            int len = stoi(s.substr(i, pos - i)); // Extract the length
            string str = s.substr(pos + 1, len); // Extract the actual string
            decoded.push_back(str);
            i = pos + 1 + len; // Move to the next encoded segment
        }
        
        return decoded;
    }
};
