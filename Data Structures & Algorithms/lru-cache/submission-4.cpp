struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
};

class LRUCache {
    Node* head;
    Node* tail;
    unordered_map<int, Node*> keyToNode{};
    int capacity;
    unsigned size;

    void addToFront (Node* newNode) {
        Node* headNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = headNext;
        if (headNext) {
            headNext->prev = newNode;
        } else {
            tail = newNode;
        }
    }

    void removeNode (Node* node) {
        Node* afterNode = node->next;
        node->prev->next = afterNode;
        if (afterNode) {
            afterNode->prev = node->prev;
        } else {
            tail = node->prev;
        }
    }
public:
    LRUCache(int capacity): capacity(capacity) {
        size = 0;
        head = new Node{0, 0, nullptr, nullptr};
        tail = head;
    }
    
    int get(int key) {
        auto find = keyToNode.find(key);

        if (find == keyToNode.end()) {
            return -1;
        }

        Node* foundNode = find->second;
        removeNode(foundNode);
        addToFront(foundNode);

        return foundNode->value;
    }
    
    void put(int key, int value) {
        if (keyToNode.find(key) != keyToNode.end()) {
            Node* foundNode = keyToNode.find(key)->second;
            foundNode->value = value;
            removeNode(foundNode);
            addToFront(foundNode);
            return;
        }

        if (size == capacity) {
            keyToNode.erase(tail->key);
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            --size;
        }

        Node* newNode = new Node{key, value, nullptr, nullptr};
        keyToNode[key] = newNode;
        ++size;

        addToFront(newNode);
    }
};
