class Solution {
    typedef pair<double, int> distCoorPair;
    priority_queue<distCoorPair> maxHeap;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (int i = 0; i < points.size(); ++i) {
            double dist = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);

            maxHeap.push({dist, i});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        res.reserve(k);
        while (maxHeap.size()) {
            res.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }

        return res;
    }
};
