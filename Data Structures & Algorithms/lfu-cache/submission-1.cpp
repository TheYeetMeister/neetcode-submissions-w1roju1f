class LFUCache {
    struct Node {
        int key;
        int val;
        int freq;
        Node* next;
        Node* prev;
    };

    unordered_map<int, Node*> keyToNode;
    unordered_map<int, Node*> headFreqList;
    unordered_map<int, Node*> tailFreqList;

    int min;

    int space;

    bool isFreqEmpty(int freq) {
        return headFreqList[freq]->next == tailFreqList[freq];
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void updateNode(Node* node) {
        removeNode(node);

        if (isFreqEmpty(node->freq) && node->freq == min) {
            ++min;
        }

        ++(node->freq);
        insertNode(node);
    }

    void insertNode(Node* node) {
        int freq = node->freq;
        Node* head;
        Node* tail;

        if (headFreqList.find(freq) == headFreqList.end()) {
            head = new Node{};
            tail = new Node{};

            headFreqList[freq] = head;
            tailFreqList[freq] = tail;
            head->next = tail;
            tail->prev = head;
        } else {
            head = headFreqList[freq];
            tail = tailFreqList[freq];
        }

        // directly inserts the node
        Node* next = head->next;

        head->next = node;
        node->prev = head;

        node->next = next;
        next->prev = node;
    }

public:
    LFUCache(int capacity): space(capacity) {}
    
    int get(int key) {
        if (keyToNode[key] == nullptr) {
            return -1;
        }

        Node* node = keyToNode[key];
        updateNode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (keyToNode[key] != nullptr) {
            Node* node = keyToNode[key];
            node->val = value;
            updateNode(node);
            return;
        }
        
        if (space == 0) {
            Node* leastFreq = tailFreqList[min]->prev;
            keyToNode[leastFreq->key] = nullptr;
            removeNode(leastFreq);
            delete leastFreq;
        } else {
            --space;
        }

        if (min != 1) {
            min = 1;
        }

        Node* newNode = new Node{key, value, 1};
        keyToNode[key] = newNode; 
        insertNode(newNode);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */