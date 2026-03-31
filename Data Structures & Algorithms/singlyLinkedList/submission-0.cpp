struct node {
    int value;
    node* nextNode;
};

class LinkedList {
    node* headNode;
    node* tailNode;
public:
    LinkedList(): headNode(nullptr), tailNode(nullptr) {}

    ~LinkedList() {
        node* temp;
        while(headNode) {
            temp = headNode->nextNode;
            delete headNode;
            headNode = temp;
        }
    }

    int get(int index) {
        node* temp = headNode;

        for (int i = 0; i < index && temp; ++i, temp = temp->nextNode);

        return (temp) ? temp->value : -1;
    }

    void insertHead(int val) {
        node* temp = new node{val, nullptr};

        if (headNode) {
            temp->nextNode = headNode;
            headNode = temp;
        } else {
            headNode = temp;
            tailNode = temp;
        }
    }
    
    void insertTail(int val) {
        node* temp = new node{val, nullptr};

        if (tailNode) {
            tailNode->nextNode = temp;
            tailNode = temp;
        } else {
            headNode = temp;
            tailNode = temp;
        }
    }

    bool remove(int index) {
        node* temp = headNode;
        node* prevTemp = nullptr;

        for (int i = 0; 
            i < index && temp != nullptr;
            ++i, prevTemp = temp, temp = temp->nextNode);

        if (!temp) {
            return false;
        }

        if (!temp->nextNode) {
            tailNode = prevTemp;
        }

        if (!prevTemp) {
            headNode = temp->nextNode;
        } else {
            prevTemp->nextNode = temp->nextNode;
        }

        delete temp;

        return true;        
    }

    vector<int> getValues() {
        vector<int> nodes;
        
        for (node* temp = headNode; temp != nullptr; temp = temp->nextNode) {
            nodes.push_back(temp->value);
        }

        return nodes;
    }
};
