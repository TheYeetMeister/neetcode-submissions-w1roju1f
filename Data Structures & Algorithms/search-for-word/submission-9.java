class Solution {
    int ROW;
    int COL;
    String word;
    char[][] board;
    static final int[][] lambda = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };

    private boolean dfs(Set<Integer> prevs, int i, int j, int wordPos) {
        if (wordPos == word.length()) {
            return true;
        } else if (i < 0 || i == ROW ||
                    j < 0 || j == COL ||
                    prevs.contains(i * COL + j) ||
                    board[i][j] != word.charAt(wordPos)) {
                        return false;
        }

        prevs.add(i * COL + j);

        for (int[] step: lambda) {
            if (dfs(prevs, i + step[0], j + step[1], wordPos + 1)) {
                return true;
            }
        }

        prevs.remove(i * COL + j);

        return false;
    }

    public boolean exist(char[][] board, String word) {
        this.ROW = board.length;
        this.COL = board[0].length;
        this.word = word;
        this.board = board;

        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                Set<Integer> prevs = new HashSet<>();
                if (dfs(prevs, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
}
