class MinStack {
    Stack<Integer> buf = new Stack<>();
    Stack<Integer> minBuf = new Stack<>();

    public MinStack() {}
    
    public void push(int val) {
        buf.push(val);

        int minValue = (minBuf.empty()) ? Integer.MAX_VALUE: minBuf.peek();

        minBuf.push(Math.min(minValue, val));
    }
    
    public void pop() {
        buf.pop();
        minBuf.pop();
    }
    
    public int top() {
        return buf.peek();
    }
    
    public int getMin() {
        return minBuf.peek();
    }
}
