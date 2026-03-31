class Solution {
    List<List<String>> res;
    List<String> partion;
    String s;

    static private boolean isPali(String sub) {
        int index = sub.length() / 2;
        int end = sub.length() - 1;

        for (int i = 0; i < index; ++i) {
            if (sub.charAt(i) != sub.charAt(end - i)) {
                return false;
            }
        }
        return true;
    }

    private void dfs(StringBuilder sb, int i) {
        if (i == s.length() && sb.length() > 0) {
            return;
        } else if (i == s.length()) {
            res.add(new ArrayList<>(partion));
            return;
        }
        
        sb.append(s.charAt(i));
        dfs(sb, i + 1);

        if (isPali(sb.toString())) {
            partion.add(sb.toString());
            dfs(new StringBuilder(), i + 1);
            partion.remove(partion.size() - 1);
        }

        sb.deleteCharAt(sb.length() - 1);
    }

    public List<List<String>> partition(String s) {
        res = new ArrayList<>();
        partion = new ArrayList<>();
        this.s = s;

        dfs(new StringBuilder(), 0);

        return res;
    }
}
