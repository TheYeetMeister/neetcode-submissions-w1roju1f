class Solution {
    StringBuilder sb;
    List<String> res;
    int n;

    private void dfs(int openCnt, int closeCnt) {
        if (closeCnt == n) {
            res.add(sb.toString());
            return;
        }

        if (openCnt < n) {
            sb.append('(');
            dfs(openCnt + 1, closeCnt);
            sb.deleteCharAt(sb.length() - 1);
        }

        if (openCnt > closeCnt) {
            sb.append(')');
            dfs(openCnt, closeCnt + 1);
            sb.deleteCharAt(sb.length() - 1);
        }
    }

    public List<String> generateParenthesis(int n) {
        sb = new StringBuilder();
        res = new ArrayList<>();
        this.n = n;

        dfs(0, 0);

        return res;
    }
}