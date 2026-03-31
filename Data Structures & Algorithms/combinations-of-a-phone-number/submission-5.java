class Solution {
    private static final Map<Character, String> DIGITS_TO_CHAR;

    static {
        Map<Character, String> tempMap = new HashMap<>();
        tempMap.put('2', "abc");
        tempMap.put('3', "def");
        tempMap.put('4', "ghi");
        tempMap.put('5', "jkl");
        tempMap.put('6', "mno");
        tempMap.put('7', "pqrs");
        tempMap.put('8', "tuv");
        tempMap.put('9', "wxyz");
        DIGITS_TO_CHAR = Collections.unmodifiableMap(tempMap);
    }

    StringBuilder sb;
    List<String> res;

    private void dfs(String digits, int i) {
        if (i == digits.length()) {
            res.add(sb.toString());
            return;
        }

        for (char c: DIGITS_TO_CHAR.get(digits.charAt(i)).toCharArray()) {
            sb.append(c);
            dfs(digits, i + 1);
            sb.deleteCharAt(sb.length() - 1);
        }
    }

    public List<String> letterCombinations(String digits) {
        sb = new StringBuilder();
        res = new ArrayList<>();

        if (digits.length() == 0) {
            return res;
        }

        dfs(digits, 0);

        return res;
    }
}
