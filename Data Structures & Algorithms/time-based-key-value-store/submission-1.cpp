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
        string res = "";
        int left = 0, right = time.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            auto [x, y, z] = time[mid];
            if (z <= timestamp) {
                res = y;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};
