class Solution {
    int ROWS;
    int COLS;

    private int calAllGrids(int[][] matrix) {
        ROWS = matrix.length;
        COLS = matrix[0].length;

        return ROWS * COLS;
    }

    private Pair<Integer, Integer> calRowGridNum(int index) {
        int row = index / COLS;
        int col = index % COLS;

        return new Pair<>(row, col);
    }

    public boolean searchMatrix(int[][] matrix, int target) {
        int l = 0, r = calAllGrids(matrix) - 1;

        while (l <= r) {
            int mid = l + ((r - l) / 2);
            Pair<Integer, Integer> coor = calRowGridNum(mid);

            int row = coor.getKey();
            int col = coor.getValue();

            if (matrix[row][col] > target) {
                r = mid - 1;
            } else if (matrix[row][col] < target) {
                l = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
}
