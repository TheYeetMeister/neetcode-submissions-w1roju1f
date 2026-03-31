class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> connections;
        
        for (vector<int> edge: edges) {
            connections[edge[0]].push_back(edge[1]);
            connections[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        queue<int> bfs;

        bfs.push(0);

        int visitedNodes = 0;

        while (!bfs.empty()) {
            ++visitedNodes;
            int node = bfs.front();
            bfs.pop();
            bool foundParent = false;
            visited[node] = true;

            for (int nei: connections[node]) {
                if (!visited[nei]) {
                    bfs.push(nei);
                } else if (!foundParent) {
                    foundParent = true;
                } else {
                    return false;
                }
            }
        }

        return visitedNodes == n;
    }
};
