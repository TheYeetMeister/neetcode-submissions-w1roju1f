class DSU {
    unordered_map<int, unordered_map<int, pair<int, int>>> parent;
    unordered_map<int, unordered_map<int, int>> rank;
public:
    DSU(vector<vector<int>>& points) {
        for (vector<int> point: points) {
            int x = point[0];
            int y = point[1];
            parent[x][y] = {x, y};
            rank[x][y] = 1;
        }
    }

    pair<int, int> find(pair<int, int> i) {
        while (i != parent[i.first][i.second]) {
            int px = parent[i.first][i.second].first;
            int py = parent[i.first][i.second].second;

            parent[i.first][i.second] = {px, py};
            i = parent[i.first][i.second];
        }

        return i;
    }

    bool conjoin(pair<int, int> i, pair<int, int> j) {
        auto pi = find(i);
        auto pj = find(j);

        if (pi == pj) {
            return false;
        }

        if (rank[pi.first][pi.second] > rank[pj.first][pj.second]) {
            swap(pi, pj);
        }

        parent[pj.first][pj.second] = pi;
        rank[pi.first][pi.second] += rank[pj.first][pj.second];

        return true;
    }
};

class Solution {
    int calCost(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        DSU dsu(points);

        //first num is edge weight, second and third ints are variable nums to pair in points vector
        vector<vector<int>> edges;

        for (int i = 0; i < points.size(); ++i) {
            for (int j = 0; j < points.size(); ++j) {
                if (i != j) {
                    edges.push_back({calCost(points[i], points[j]), i, j});
                }
            }
        }

        sort(edges.begin(), edges.end());
        
        int cost = 0;
        for (vector<int> edge: edges) {
            if (dsu.conjoin({points[edge[1]][0], points[edge[1]][1]},
                        {points[edge[2]][0], points[edge[2]][1]})) {
                            cost += edge[0];
            }
        }
        
        return cost;
    }
};
