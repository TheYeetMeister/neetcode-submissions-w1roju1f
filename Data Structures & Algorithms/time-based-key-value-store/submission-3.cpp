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
        int left = 0;
        int right = data[key].size() - 1;

        int midChosen = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (data[key][mid].first > timestamp) {
                right = mid - 1;
            } else if (data[key][mid].first < timestamp) {
                midChosen = mid;
                left = mid + 1;
            } else {
                return data[key][mid].second;
            }
        }

        return midChosen == -1 ? "" : data[key][midChosen].second;
    }
};
