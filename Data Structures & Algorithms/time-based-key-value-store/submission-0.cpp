class TimeMap {
private: 
    vector<tuple<string, string, int>> time;
public:
    TimeMap() {
        vector<tuple<string, string, int>> time;
    }
    
    void set(string key, string value, int timestamp) {
        time.push_back({key, value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int max_time = 0;
        string res = "";
        for (auto [x, y, z] : time) {
            if (x == key and z <= timestamp) {
                if (max_time < z) {
                    max_time = z;
                    res = y;
                }
            }
        }
        return res;
    }
};
