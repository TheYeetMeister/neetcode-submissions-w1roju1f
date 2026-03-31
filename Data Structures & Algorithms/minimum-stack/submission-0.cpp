class MinStack {
public:
    stack<int> innerStack;
    stack<int> min;
    MinStack() {
        innerStack = {};
        min = {};
    }
    
    void push(int val) {
        innerStack.push(val);

        if (min.empty() || min.top() >= val) {
            min.push(val);
        }
    }
    
    void pop() {
        if (min.top() == innerStack.top()) {
            min.pop();
        }

        innerStack.pop();
    }
    
    int top() {
        return innerStack.top();
    }
    
    int getMin() {
        return min.top();
    }
};
