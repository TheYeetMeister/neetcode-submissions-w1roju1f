class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        vector<int> temp(n, INT_MAX);
        dist[src] = 0;
        temp[src] = 0;

        for (int i = 0; i < k + 1; ++i) {
            for (const vector<int>& nei: flights) {
                int u = nei[0];
                int v = nei[1];
                int wei = nei[2];
                if (dist[u] != INT_MAX && dist[u] + wei < temp[v]) {
                    temp[v] = dist[u] + wei;
                }
            }

            for (int j = 0; j < n; ++j) {
                dist[j] = temp[j];
            }
        }

        return (dist[dst] == INT_MAX) ? -1: dist[dst];
    }
};
