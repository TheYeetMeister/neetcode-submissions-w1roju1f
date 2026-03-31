class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //organized like nei[ui] = make_pair(vi, ti)
        unordered_map<int, vector<pair<int, int>>> nei;
        unordered_set<int> visited;

        for (vector<int> time: times) {
            nei[time[0]].push_back(make_pair(time[1], time[2]));
        }

        int time = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push(make_pair(0, k));

        while (!minHeap.empty()) {
            pair<int, int> checkedNode = minHeap.top();
            minHeap.pop();

            if (visited.find(checkedNode.second) == visited.end()) {
                time = checkedNode.first;
                visited.insert(checkedNode.second);

                for (auto nearest: nei[checkedNode.second]) {
                    if (visited.find(nearest.first) == visited.end()) {
                        minHeap.push(make_pair(time + nearest.second, nearest.first));
                    }
                }
            }
        }

        return (visited.size() == n)? time: -1;
    }
};
