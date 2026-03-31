class MyHashSet {
    vector<bool> keys;

    void resizeVector(int newSize) {
        vector<bool> newVector(newSize);

        for (int i = 0; i < keys.size(); ++i) {
            newVector[i] = keys[i];
        }

        keys = newVector;
    }

    bool keyIsInHash(int key) {
        if (key >= keys.size()) {
            return false;
        }

        return keys[key];
    }
public:
    MyHashSet() {
        keys = vector<bool>(0);
    }
    
    void add(int key) {
        if (key >= keys.size()) {
            resizeVector(key + 1);
        }

        keys[key] = true;
    }
    
    void remove(int key) {
        if (keyIsInHash(key)) {
            keys[key] = false;
        }
    }
    
    bool contains(int key) {
        return keyIsInHash(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */