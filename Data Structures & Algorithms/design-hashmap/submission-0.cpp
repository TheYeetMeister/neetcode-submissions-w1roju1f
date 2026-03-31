class MyHashMap {
    const int maxSize = 1000001;
    vector<int> buf = vector<int>(1000001, -1);
public:
    MyHashMap() {

    }
    
    void put(int key, int value) {
        buf[key] = value;
    }
    
    int get(int key) {
        return buf[key];
    }
    
    void remove(int key) {
        buf[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */