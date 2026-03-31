class Solution {
    private static final HashMap<Character, Character> parenMap = new HashMap<>();
    static {
        parenMap.put('[', ']');
        parenMap.put('(', ')');
        parenMap.put('{', '}');
    }

    private boolean isOpenParenthesis(char c) {
        return c == '[' || c == '(' || c == '{';
    }

    public boolean isValid(String s) {
        Stack<Character> charStack = new Stack<>();

        for (char c: s.toCharArray()) {
            if (isOpenParenthesis(c)) {
                charStack.push(parenMap.get(c));
            } else if (charStack.empty() || charStack.pop() != c) {
                return false;
            }
        }

        return charStack.empty();
    }
}
