class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> p;
        for (int i = 0; i < position.size(); i++) {
            p.push_back({position[i], speed[i]});
        }
        sort(p.rbegin(), p.rend());
        vector<double> st;
        for (auto i : p) {
            double tmp = (double)(target - i.first)/i.second;
            st.push_back(tmp);
            if (st.size() >= 2 and st.back() <= st[st.size()-2]){
                st.pop_back();
            }
        }
        return st.size();
    }
};
