class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neigh(n);

        for (vector<int> nei: edges) {
            neigh[nei[0]].push_back(nei[1]);
            neigh[nei[1]].push_back(nei[0]);
        }

        unordered_set<int> unvisited;
        for (int i = 0; i < n; ++i) {
            unvisited.insert(i);
        }

        int count = 0;
        queue<int> bfs;

        while (!unvisited.empty()) {
            bfs.push(*unvisited.begin());
            ++count;

            while (!bfs.empty()) {
                int node = bfs.front();
                bfs.pop();
                unvisited.erase(node);
                
                for (int nei: neigh[node]) {
                    if (unvisited.find(nei) != unvisited.end()) {
                        bfs.push(nei);
                    }
                }
            }
        }

        return count;
    }
};
