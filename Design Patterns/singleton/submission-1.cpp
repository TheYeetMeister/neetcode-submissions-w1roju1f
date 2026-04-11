class Singleton {
private:
    string staticValue = "";
    Singleton() {}

public:

    static Singleton *getInstance() {
        static Singleton instance;
        return &instance;
    }

    string getValue() {
        return staticValue;
    }

    void setValue(string &value) {
        staticValue = value;
    }
};
