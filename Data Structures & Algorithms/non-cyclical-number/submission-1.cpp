class Solution {
public:
    bool isHappy(int n) {
        string s = to_string(n);
        int sum = 0;
        while (true) {
            sum = 0;
            for (int i = 0; i < s.size(); i++)  {
                int c = s[i] - '0';
                sum += c * c;
            }
            s = to_string(sum);
            if (s.size() == 1)
                break;
        }
        if (s == "1") 
            return  true;
        else return  false;
    }
};
