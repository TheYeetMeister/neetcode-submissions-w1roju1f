class Solution {
    int ROW;
    int COL;
    void markRowCol(int i, int j, vector<vector<int>>& matrix) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
    }

    void checkZero(int i, int j, vector<vector<int>>& matrix) {
        if (!matrix[i][0] || !matrix[0][j]) {
            matrix[i][j] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        ROW = matrix.size();
        COL = matrix[0].size();

        bool topRow = false;

        for (int j = 0; j < COL; ++j) {
            if (!matrix[0][j]) {
                topRow = true;
                break;
            }
        }

        for (int i = 1; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (!matrix[i][j]) {
                    markRowCol(i, j, matrix);
                }
            }
        }

        for (int i = 1; i < ROW; ++i) {
            for (int j = 1; j < COL; ++j) {
                checkZero(i, j, matrix);
            }
        }

        if (!matrix[0][0]) {
            for (int i = 1; i < ROW; ++i) {
                matrix[i][0] = 0;
            }
        }

        if (topRow) {
            for (int j = 0; j < COL; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};
