struct node {
    int val;
    node* prev;
    node* next;
};

class LinkedList {
    node* head;
    node* tail;
    int size;
    node* createNewNode(int val) {
        return new node{val, nullptr, nullptr};
    }

    void redirectNeighbors(node* newNode) {
        newNode->prev->next = newNode;
        newNode->next->prev = newNode;
    }

    void removeNode(node* listNode) {
        node* prevNode = listNode->prev;
        node* nextNode = listNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete listNode;
    }

    node* goToNode(int index) {
        if (index < 0 || index >= size) {
            return nullptr;
        }
        node* curr = head->next;
        for (int i = 0; i < index; ++i, curr = curr->next);
        return curr;
    }
public:
    LinkedList(): size(0) {
        head = createNewNode(0);
        tail = createNewNode(0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int index) {
        node* curr = goToNode(index);

        return (curr) ? curr->val: -1;
    }

    void insertHead(int val) {
        ++size;

        node* newNode = createNewNode(val);

        newNode->next = head->next;
        newNode->prev = head;

        redirectNeighbors(newNode);
    }
    
    void insertTail(int val) {
        ++size;

        node* newNode = createNewNode(val);

        newNode->next = tail;
        newNode->prev = tail->prev;

        redirectNeighbors(newNode);
    }

    bool remove(int index) {
        node* currNode = goToNode(index);

        if (!currNode) {
            return false;
        }

        removeNode(currNode);
        --size;
        return true;
    }

    vector<int> getValues() {
        node* currNode = head->next;
        vector<int> returnArray;
        returnArray.reserve(size);

        for (int i = 0; i < size; ++i, currNode = currNode->next) {
            returnArray.push_back(currNode->val);
        }

        return returnArray;
    }
};
