class Solution {
    interface operation {
        int eval(int a, int b);
    }

    static final Map<String, operation> ops = new HashMap<>();

    static {
        ops.put("+", (int a, int b) -> a + b);
        ops.put("-", (int a, int b) -> a - b);
        ops.put("*", (int a, int b) -> a * b);
        ops.put("/", (int a, int b) -> a / b);
    }

    public int evalRPN(String[] tokens) {
        Stack<Integer> values = new Stack<>();

        for (String i: tokens) {
            if (ops.containsKey(i)) {
                int b = values.pop();
                int a = values.pop();
                values.push(ops.get(i).eval(a, b));
            } else {
                values.push(Integer.parseInt(i));
            }
        }

        return values.peek();
    }
}
