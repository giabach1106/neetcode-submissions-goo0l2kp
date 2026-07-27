class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> time;
public:
    TimeMap() {
        unordered_map<string, vector<pair<string, int>>> time;
    }
    
    void set(string key, string value, int timestamp) {
        time[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string res = "";
        int left = 0, right = time[key].size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            string x = time[key][mid].first;
            int y = time[key][mid].second;
            if (y <= timestamp) {
                left = mid + 1;
                res = x;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};
