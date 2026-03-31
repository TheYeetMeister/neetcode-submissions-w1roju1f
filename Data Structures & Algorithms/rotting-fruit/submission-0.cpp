class Solution {
    int ROW, COL;

    int directions[4][2] {
        {1, 0},
        {0, 1},
        {-1,0},
        {0,-1}
    };

    void findStartingPoses(vector<vector<int>>& grid, queue<pair<int, int>>& bfs) {
        ROW = grid.size();
        COL = grid[0].size();

        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (grid[i][j] == 2) {
                    bfs.push(make_pair(i, j));
                }
            }
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> bfs;
        findStartingPoses(grid, bfs);

        int timeElapsed = 0;

        while (!bfs.empty()) {
            int size = bfs.size();
            int rotted = false;

            for (int j = 0; j < size; ++j) {
                pair<int, int> pos = bfs.front();
                bfs.pop();
                
                for (int i = 0; i < 4; ++i) {
                    int row = pos.first + directions[i][0];
                    int col = pos.second + directions[i][1];

                    if (row >= 0 && row < ROW &&
                        col >= 0 && col < COL &&
                        grid[row][col] == 1) {
                        grid[row][col] = 2;
                        bfs.push(make_pair(row, col));
                        rotted = true;
                    }
                }
            }

            if (rotted)
                ++timeElapsed;
        }

        //last check to see if there are any fruits that are fresh but not rotted fruit are next it
        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return timeElapsed;
    }
};
