class MyStack {
    queue<int> buf;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        buf.push(x);

        for (int i = 1; i < buf.size(); ++i) {
            buf.push(buf.front());
            buf.pop();
        }
    }
    
    int pop() {
        int val = buf.front();
        buf.pop();
        return val;
    }
    
    int top() {
        return buf.front();
    }
    
    bool empty() {
        return buf.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */