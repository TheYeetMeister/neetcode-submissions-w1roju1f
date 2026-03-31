class Solution {
    int directions[4][2] {
        {1, 0},
        {0, 1},
        {-1,0},
        {0,-1}
    };

    int ROW, COL;
    vector<vector<bool>> checked;

    void dfsEdge(int row, int col, vector<vector<char>>& board) {
        if (row < 0 || row == ROW ||
            col < 0 || col == COL ||
            checked[row][col] || 
            board[row][col] == 'X') {
                return;
        }

        checked[row][col] = true;

        for (int i = 0; i < 4; ++i) {
            dfsEdge(row + directions[i][0], col + directions[i][1], board);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        ROW = board.size();
        COL = board[0].size();
        checked = vector<vector<bool>>(ROW, vector<bool>(COL, false));

        for (int i = 0; i < ROW; ++i) {
            dfsEdge(i, 0, board);
            dfsEdge(i, COL - 1, board);
        }

        for (int j = 0; j < COL; ++j) {
            dfsEdge(0, j, board);
            dfsEdge(ROW - 1, j, board);
        }

        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (!checked[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
