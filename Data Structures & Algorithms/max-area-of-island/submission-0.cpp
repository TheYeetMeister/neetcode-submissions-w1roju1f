class Solution {
    int ROW, COL;
    void dfsCount(int i, int j, vector<vector<int>>& grid, int& curr) {
        if (i < 0 || i >= ROW ||
            j < 0 || j >= COL ||
            !grid[i][j]) {
            return;
        }

        grid[i][j] = 0;
        ++curr;

        dfsCount(i + 1, j, grid, curr);
        dfsCount(i - 1, j, grid, curr);
        dfsCount(i, j + 1, grid, curr);
        dfsCount(i, j - 1, grid, curr);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        ROW = grid.size();
        COL = grid[0].size();

        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (grid[i][j]) {
                    int curr = 0;
                    dfsCount(i, j, grid, curr);

                    res = max(res, curr);
                }
            }
        }

        return res;
    }
};
