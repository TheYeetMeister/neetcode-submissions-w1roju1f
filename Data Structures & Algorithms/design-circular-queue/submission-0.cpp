class MyCircularQueue {
    vector<int> buf;
    int front;
    int back;
    int size;

    int iterForward(int position) {
        if (++position == buf.size()) {
            return 0;
        }

        return position;
    }
public:
    MyCircularQueue(int k): front(0), back(-1), size(0), buf(vector<int>(k)) {}
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        ++size;
        back = iterForward(back);
        buf[back] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        --size;
        front = iterForward(front);
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return buf[front];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return buf[back];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == buf.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */