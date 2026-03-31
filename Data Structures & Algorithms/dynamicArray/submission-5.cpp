class DynamicArray {
    unsigned capacity;
    unsigned currSize;
    int* buf;

    int* createNewBuf(unsigned newCapacity) {
        int* newBuf = new int[newCapacity];

        for (int i = 0; i < currSize; ++i) {
            newBuf[i] = buf[i];
        }

        return newBuf;
    }
public:
    DynamicArray(int capacity): capacity(capacity), currSize(0) {
        buf = new int[capacity];
    }

    int get(int i) {
        return buf[i];
    }

    void set(int i, int n) {
        buf[i] = n;
    }

    void pushback(int n) {
        if (currSize >= capacity) {
            resize();
        }

        buf[currSize] = n;
        ++currSize;
    }

    int popback() {
        --currSize;
        return buf[currSize];
    }

    void resize() {
        capacity *= 2;

        int* newBuf = createNewBuf(capacity);
        delete buf;
        buf = newBuf;
    }

    int getSize() {
        return currSize;
    }

    int getCapacity() {
        return capacity;
    }
};
