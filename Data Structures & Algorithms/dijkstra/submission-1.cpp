class Solution {
    unordered_map<int, vector<vector<int>>> createdEdgeMap(vector<vector<int>>& edges) {
        unordered_map<int, vector<vector<int>>> edgeMap;

        for (vector<int>& val: edges) {
            int u = val[0];
            int v = val[1];
            int w = val[2];

            edgeMap[u].push_back({v, w});
        }

        return edgeMap;
    }
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, int> distanceMap;
        vector<bool> booleanList(n, false);
        unordered_map<int, vector<vector<int>>> edgeMap = createdEdgeMap(edges);

        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> q;
        q.push({0, src});

        while (distanceMap.size() < n && q.size() > 0) {
            tuple<int, int> topElem = q.top();
            int currentCost = get<0>(topElem);
            int currNode = get<1>(topElem);
            q.pop();

            if (distanceMap.count(currNode)) continue;
            distanceMap[currNode] = currentCost;
            booleanList[currNode] = true;

            for (vector<int>& edge: edgeMap[currNode]) {
                int nei = edge[0];
                int neiCost = edge[1];

                q.push({currentCost + neiCost, nei});
            }
        }

        for (int i = 0; i < booleanList.size(); ++i) {
            if (!booleanList[i]) {
                distanceMap[i] = -1;
            }
        }

        return distanceMap;
    }
};
