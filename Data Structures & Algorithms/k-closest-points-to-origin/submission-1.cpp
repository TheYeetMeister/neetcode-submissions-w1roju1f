class Solution {
    typedef pair<double, vector<int>> distCoorPair;
    priority_queue<distCoorPair> maxHeap;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (vector<int> i: points) {
            double dist = sqrt(i[0] * i[0] + i[1] * i[1]);

            maxHeap.push({dist, i});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        res.reserve(k);
        while (maxHeap.size()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return res;
    }
};
