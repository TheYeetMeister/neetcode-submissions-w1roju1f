class Solution {
    int relativeDirections[4][2] {
        {1, 0},
        {0, 1},
        {-1,0},
        {0,-1}
    };
    int ROW, COL;

    void findTreasureChests(vector<vector<int>>& grid, queue<tuple<int, int>>& bfs) {
        ROW = grid.size();
        COL = grid[0].size();

        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (grid[i][j] == 0) {
                    bfs.push(make_tuple(i, j));
                }
            }
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<tuple<int, int>> bfs;
        findTreasureChests(grid, bfs);

        while (!bfs.empty()) {
            tuple<int, int> pos = bfs.front();
            bfs.pop();

            for (int i = 0; i < 4; ++i) {
                int row = get<0>(pos) + relativeDirections[i][0];
                int col = get<1>(pos) + relativeDirections[i][1];

                if (row < ROW && row >= 0 &&
                    col < COL && col >= 0 &&
                    grid[row][col] == INT_MAX) {
                    grid[row][col] = grid[get<0>(pos)][get<1>(pos)] + 1;
                    bfs.push(make_tuple(row, col));
                }
            }
        }
    }
};
