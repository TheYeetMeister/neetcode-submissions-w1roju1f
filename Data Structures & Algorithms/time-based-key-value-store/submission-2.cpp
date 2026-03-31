class TimeMap {
    unordered_map<string, vector<pair<int, string>>> data;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        if (data.find(key) == data.end()) {
            data[key] = vector<pair<int, string>>{{ timestamp, value }};
        } else {
            data[key].push_back(make_pair(timestamp, value));
        }
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> timeline = data[key];

        int left = 0;
        int right = timeline.size() - 1;

        string res = "";

        while (left <= right) {
            int mid = (left + right) / 2;

            if (timeline[mid].first > timestamp) {
                right = mid - 1;
            } else {
                res = timeline[mid].second;
                left = mid + 1;
            }
        }

        return res;
    }
};
