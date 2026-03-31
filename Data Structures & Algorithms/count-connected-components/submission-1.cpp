class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neigh(n);
        vector<bool> visited(n, false);

        for (vector<int> nei: edges) {
            neigh[nei[0]].push_back(nei[1]);
            neigh[nei[1]].push_back(nei[0]);
        }

        int count = 0;
        queue<int> bfs;
        int visitedPos = 0;

        for (int visitedPos = 0; visitedPos < n; ++visitedPos) {
            if (visited[visitedPos]) {
                continue;
            }

            bfs.push(visitedPos);
            ++count;

            while (!bfs.empty()) {
                int node = bfs.front();
                bfs.pop();
                visited[node] = true;
                
                for (int nei: neigh[node]) {
                    if (!visited[nei]) {
                        bfs.push(nei);
                    }
                }
            }
        }

        return count;
    }
};
