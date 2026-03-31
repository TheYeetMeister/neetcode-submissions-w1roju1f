class UFS {
public:
    unordered_map<int, int> rank;
    unordered_map<int, int> parent;

    UFS() {}

    int find(int node) {
        if (parent.find(node) == parent.end()) {
            parent[node] = node;
            rank[node] = 1;
            return node;
        }

        while (node != parent[node]) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }

        return node;
    }

    bool unionSet(int v, int u) {
        int pv = find(v);
        int pu = find(u);
        if (pv == pu) {
            return false;
        }

        if (rank[pv] > rank[pu]) {
            swap(pu, pv);
        }
        parent[pv] = pu;
        rank[pu] += rank[pv];
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UFS ufs;

        vector<int> res;

        for (vector<int> edge: edges) {
            if (!ufs.unionSet(edge[0], edge[1])) {
                res = edge;
            }
        }

        return res;
    }
};
