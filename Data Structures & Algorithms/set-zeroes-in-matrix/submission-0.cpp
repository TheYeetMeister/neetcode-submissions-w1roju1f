class Solution {
    int ROW;
    int COL;
    void setZero(int i, int j, vector<vector<int>>& matrix) {
        for (int k = 0; k < ROW; ++k) {
            matrix[k][j] = 0;
        }

        for (int k = 0; k < COL; ++k) {
            matrix[i][k] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        ROW = matrix.size();
        COL = matrix[0].size();

        stack<pair<int, int>> zeroes;

        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (!matrix[i][j]) {
                    zeroes.push({i, j});
                }
            }
        }

        while (!zeroes.empty()) {
            auto top = zeroes.top();
            zeroes.pop();

            setZero(top.first, top.second, matrix);
        }
    }
};
