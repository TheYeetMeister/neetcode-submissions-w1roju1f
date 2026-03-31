class LRUCache {
    class ListNode {
        public int key;
        public int value;
        public ListNode prev;
        public ListNode next;

        public ListNode(int key, int value) {
            this.key = key;
            this.value = value;
            prev = null;
            next = null;
        }

        public ListNode(int key, int value, ListNode prev, ListNode next) {
            this.key = key;
            this.value = value;
            this.prev = prev;
            this.next = next;
        }
    }

    int space;
    ListNode head;
    ListNode tail;
    HashMap<Integer, ListNode> position;

    private void removeListNode(ListNode rem) {
        ++space;

        rem.next.prev = rem.prev;
        rem.prev.next = rem.next;
    }

    private void insertListNode(ListNode node) {
        --space;

        ListNode temp = head.next;
        head.next = node;
        node.prev = head;

        node.next = temp;
        temp.prev = node;
    }
    
    public LRUCache(int capacity) {
        space = capacity;
        position = new HashMap<>();

        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);

        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        if (position.getOrDefault(key, null) == null) {
            return -1;
        }   

        ListNode node = position.get(key);

        removeListNode(node);
        insertListNode(node);

        return node.value;
    }
    
    public void put(int key, int value) {
        ListNode node;
        if (position.getOrDefault(key, null) == null) {
            node = new ListNode(key, value);
            position.put(key, node);
        } else {
            node = position.get(key);
            node.value = value;
            removeListNode(node);
        }

        insertListNode(node);

        if (space < 0) {
            position.put(tail.prev.key, null);
            removeListNode(tail.prev);
        }
    }
}
