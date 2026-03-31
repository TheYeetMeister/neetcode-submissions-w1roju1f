class Solution {
    int ROW, COL;
    int directions[4][2] {
        {1, 0},
        {0, 1},
        {-1,0},
        {0,-1}
    };

    int calGrid(int row, int col) {
        return row * COL + col;
    }

    int calRow(int grid) {
        return grid / COL;
    }

    int calCol(int grid) {
        return grid % COL;
    }

    void dfs(int row, int col, const int prevHeight, vector<vector<int>>& grid, unordered_set<int>& foundPoints) {
        if (row < 0 || row >= ROW ||
            col < 0 || col >= COL ||
            foundPoints.find(calGrid(row, col)) != foundPoints.end() ||
            grid[row][col] < prevHeight) {
                return;
        }

        foundPoints.insert(calGrid(row, col));

        for (int i = 0; i < 4; ++i) {
            dfs(row + directions[i][0], col + directions[i][1], grid[row][col], 
                grid, foundPoints);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROW = heights.size();
        COL = heights[0].size();

        unordered_set<int> toAtlantic;
        //for atlantic
        int j = COL - 1;
        for (int i = 0; i < ROW; ++i) {
            dfs(i, j, INT_MIN, heights, toAtlantic);
        }

        j = ROW - 1;
        for (int i = 0; i < COL; ++i) {
            dfs(j, i, INT_MIN, heights, toAtlantic);
        }

        unordered_set<int> toPacific;
        //for pacific
        j = 0;
        for (int i = 0; i < ROW; ++i) {
            dfs(i, j, INT_MIN, heights, toPacific);
        }

        for (int i = 0; i < COL; ++i) {
            dfs(j, i, INT_MIN, heights, toPacific);
        }

        vector<vector<int>> res;
        for (int i = 0; i < ROW; ++i) {
            for(int j = 0; j < COL; ++j) {
                int gridNum = calGrid(i, j);

                if (toAtlantic.find(gridNum) != toAtlantic.end() &&
                    toPacific.find(gridNum) != toPacific.end()) {
                        res.push_back(vector<int>{i, j});
                }
            }
        }

        return res;
    }
};
