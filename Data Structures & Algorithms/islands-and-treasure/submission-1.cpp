class Solution {
    int relativeDirections[4][2] {
        {1, 0},
        {0, 1},
        {-1,0},
        {0,-1}
    };
    int ROW, COL;

    void findTreasureChests(vector<vector<int>>& grid, queue<pair<int, int>>& bfs) {
        ROW = grid.size();
        COL = grid[0].size();

        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (grid[i][j] == 0) {
                    bfs.push(make_pair(i, j));
                }
            }
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> bfs;
        findTreasureChests(grid, bfs);

        while (!bfs.empty()) {
            pair<int, int> pos = bfs.front();
            bfs.pop();

            for (int i = 0; i < 4; ++i) {
                int row = pos.first + relativeDirections[i][0];
                int col = pos.second + relativeDirections[i][1];

                if (row < ROW && row >= 0 &&
                    col < COL && col >= 0 &&
                    grid[row][col] == INT_MAX) {
                    grid[row][col] = grid[pos.first][pos.second] + 1;
                    bfs.push(make_pair(row, col));
                }
            }
        }
    }
};
