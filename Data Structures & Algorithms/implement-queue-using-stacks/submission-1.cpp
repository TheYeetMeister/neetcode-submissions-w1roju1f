class MyQueue {
    stack<int> buf;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> temp;

        for (int i = 0; i < buf.size();) {
            temp.push(buf.top());
            buf.pop();
        }

        buf.push(x);

        for (int i = 0; i < temp.size();) {
            buf.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        int val = buf.top();
        buf.pop();
        return val;
    }
    
    int peek() {
        return buf.top();
    }
    
    bool empty() {
        return buf.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */