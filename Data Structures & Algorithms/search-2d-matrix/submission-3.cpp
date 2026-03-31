class Solution {
public:
    int calculateRow(int n, int colCount) {
        return n / colCount;
    }

    int calculateCol(int n, int colCount) {
        return n % colCount;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() * matrix[0].size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (matrix[calculateRow(mid, matrix[0].size())][calculateCol(mid, matrix[0].size())] > target) {
                right = mid - 1;
            } else if (matrix[calculateRow(mid, matrix[0].size())][calculateCol(mid, matrix[0].size())] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
