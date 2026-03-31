class Solution {
    int row, col;
    void flipNeighboringCells(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || i >= row ||
            j < 0 || j >= col ||
            grid[i][j] == '0') {
                return;
        }

        grid[i][j] = '0';

        flipNeighboringCells(i + 1, j, grid);
        flipNeighboringCells(i - 1, j, grid);
        flipNeighboringCells(i, j + 1, grid);
        flipNeighboringCells(i, j - 1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();

        int count = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    flipNeighboringCells(i, j, grid);
                }
            }
        }

        return count;
    }
};
