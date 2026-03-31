class FreqStack {
    vector<int> buf;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        buf.push_back(val);
    }
    
    int pop() {
        unordered_map<int, int> counts;
        vector<int> vals;
        int maxFreq = 0;

        for (int i: buf) {
            if (!counts[i]) {
                vals.push_back(i);
            }
            maxFreq = max(maxFreq, ++counts[i]);
        }

        unordered_set<int> maxVals;
        for (int i: vals) {
            if (counts[i] == maxFreq) {
                maxVals.insert(i);
            }
        }

        int val = -1;

        for (int i = buf.size() - 1; i >= 0; --i) {
            if (maxVals.find(buf[i]) != maxVals.end()) {
                val = buf[i];
                buf.erase(buf.begin() + i);
                break;
            }
        }

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */