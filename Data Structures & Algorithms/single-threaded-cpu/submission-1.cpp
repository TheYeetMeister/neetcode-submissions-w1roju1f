class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); ++i) {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());
        int time = 0;
        int i = 0;
        priority_queue<
            vector<int>, 
            vector<vector<int>>, 
            greater<vector<int>>
        > minHeap;
        vector<int> res;
        res.reserve(tasks.size());

        while (i < tasks.size() || minHeap.size() > 0) {
            while (i < tasks.size() && tasks[i][0] <= time) {
                minHeap.push(vector<int>{tasks[i][1], tasks[i][2]});
                ++i;
            }

            if (minHeap.empty()) {
                time = tasks[i][0];
                minHeap.push(vector<int>{tasks[i][1], tasks[i][2]});
                ++i;
            }

            vector<int> task = minHeap.top();
            minHeap.pop();
            time += task[0];
            res.push_back(task[1]);
        }

        return res;
    }
};