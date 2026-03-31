class DynamicArray {
public:
    int* insideArray;
    unsigned int capacity;
    unsigned int count;

    DynamicArray(unsigned int capacity): capacity(capacity), count(0) {
        insideArray = new int(capacity);
    }

    ~DynamicArray() {
        delete[] insideArray;
    }

    int get(unsigned int i) {
        if (i >= 0 && i < count) {
            return insideArray[i];
        }
    }

    void set(unsigned int i, int n) {
        if (i >= 0 && i < count) {
            insideArray[i] = n;
        }
    }

    void pushback(int n) {
        if (count >= capacity) {
            resize();
        }

        insideArray[count] = n;

        ++count;
    }

    int popback() {
        if (count <= 0) {
            return 0;
        }

        --count;

        return insideArray[count];
    }

    void resize() {
        unsigned oldCapacity = capacity;
        capacity *= 2;
        int* newArray = new int(capacity);

        for (unsigned i = 0; i < oldCapacity; ++i) {
            newArray[i] = insideArray[i];
        }

        delete[] insideArray;

        insideArray = newArray;
    }

    int getSize() {
        return count;
    }

    int getCapacity() {
        return capacity;
    }
};
