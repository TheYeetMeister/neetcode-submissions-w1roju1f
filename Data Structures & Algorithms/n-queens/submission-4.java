class Solution {
    int n;
    List<List<String>> res;
    List<String> board;
    Set<Integer> col;
    Set<Integer> diagRight;
    Set<Integer> diagLeft;
    
    private void dfs(int i) {
        if (i == n) {
            res.add(new ArrayList<>(board));
            return;
        }

        StringBuilder sb = new StringBuilder();
        for (int k = 0; k < n; ++k) {
            sb.append('.');
        }

        for (int j = 0; j < n; ++j) {
            if (!col.contains(j) &&
                !diagRight.contains(i - j) &&
                !diagLeft.contains(i + j)) {
                    col.add(j);
                    diagRight.add(i - j);
                    diagLeft.add(i + j);
                    sb.setCharAt(j, 'Q');
                    
                    board.add(sb.toString());
                    dfs(i + 1);
                    board.remove(board.size() - 1);

                    col.remove(j);
                    diagRight.remove(i - j);
                    diagLeft.remove(i + j);
                    sb.setCharAt(j, '.');
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {
        this.n = n;
        res = new ArrayList<>();
        board = new ArrayList<>();
        diagRight = new HashSet<>();
        col = new HashSet<>();
        diagLeft = new HashSet<>();

        dfs(0);

        return res;
    }
}
