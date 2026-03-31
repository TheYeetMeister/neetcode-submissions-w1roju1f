class Solution {
    int N;

    int adj[4][2] {
        {1, 0},
        {0, 1},
        {-1,0},
        {0,-1}
    };

    bool validPos(int row, int col) {
        return row >= 0 && row < N && col >= 0 && col < N;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        N = grid.size();
        unordered_set<int> visited;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        int maxHeight = grid[0][0];
        //height, row, col
        minHeap.push({grid[0][0], 0, 0});

        while (!minHeap.empty()) {
            vector<int> top = minHeap.top();
            minHeap.pop();

            maxHeight = max(top[0], maxHeight);

            if (top[1] == N - 1 && top[2] == N - 1) {
                return max(maxHeight, grid[top[1]][top[2]]);
            }

            for (int i = 0; i < 4; ++i) {
                int newRow = top[1] + adj[i][0];
                int newCol = top[2] + adj[i][1];

                if (!validPos(newRow, newCol) || visited.count(newRow * N + newCol)) {
                    continue;
                }

                visited.insert(newRow * N + newCol);

                minHeap.push({grid[newRow][newCol], newRow, newCol});
            }
        }

        return -1;
    }
};
