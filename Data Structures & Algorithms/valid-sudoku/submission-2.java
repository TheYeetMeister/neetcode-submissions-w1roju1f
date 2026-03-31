class Solution {
    private int calculateGrid(int i, int j) {
        return (i / 3 * 3) + (j / 3);
    }
    public boolean isValidSudoku(char[][] board) {
        List<Set<Character>> columnListSet = new ArrayList<>(9);
        for (int i = 0; i < 9; ++i) {
            columnListSet.add(new HashSet<>());
        }

        List<Set<Character>> gridListSet = new ArrayList<>(9);
        for (int i = 0; i < 9; ++i) {
            gridListSet.add(new HashSet<>());
        }

        for (int i = 0; i < board.length; ++i) {
            Set<Character> rowSet = new HashSet<>();
            for (int j = 0; j < board[i].length; ++j) {
                char currChar = board[i][j];
                if (currChar == '.') {
                    continue;
                }

                if (rowSet.contains(currChar)) {
                    return false;
                }
                rowSet.add(currChar);

                Set<Character> colSet = columnListSet.get(j);
                if (colSet.contains(currChar)) {
                    return false;
                }
                colSet.add(currChar);

                int gridIndex = calculateGrid(i, j);
                Set<Character> gridSet = gridListSet.get(gridIndex);
                if (gridSet.contains(currChar)) {
                    return false;
                }
                gridSet.add(currChar);
            }
        }

        return true;
    }
}
