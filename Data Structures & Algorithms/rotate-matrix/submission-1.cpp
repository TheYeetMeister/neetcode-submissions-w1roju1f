class Solution {
    void swapSingleGrids(vector<vector<int>>& matrix, int i, int j) {
        int n = matrix.size() - 1;

        int temp = matrix[i][j];

        matrix[i][j] = matrix[n - j][i];
        matrix[n - j][i] = matrix[n - i][n - j];
        matrix[n - i][n - j] = matrix[j][n - i];
        matrix[j][n - i] = temp;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int gridsToSwitch = n - 1;
        int rowsTowardCenter = n / 2;

        for (int i = 0; i < rowsTowardCenter; ++i) {
            for (int j = i ; j < gridsToSwitch - i; ++j) {
                swapSingleGrids(matrix, i, j);
            }
        }
    }
};
