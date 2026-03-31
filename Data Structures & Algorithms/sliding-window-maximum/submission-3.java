class Node {
    int value;
    int count;

    Node(int value, int count) {
        this.value = value;
        this.count = count;
    }

    public int getValue() {
        return value;
    }

    public int getCount() {
        return count;
    }

    public void incrementCount() {
        ++count;
    }

    public void decrementCount() {
        --count;
    }

    public boolean isCountZero() {
        return count == 0;
    }
}

class NodeMax implements Comparator<Node> {
    @Override
    public int compare(Node o1, Node o2) {
        return Integer.compare(o2.getValue(), o1.getValue());
    }
}

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] res = new int[nums.length - k + 1];

        PriorityQueue<Node> maxHeap = new PriorityQueue<>(new NodeMax());
        HashMap<Integer, Node> valueNodes = new HashMap<>();

        for (int i = 0; i < k - 1; ++i) {
            if (valueNodes.containsKey(nums[i])) {
                valueNodes.get(nums[i]).incrementCount();
            } else {
                Node newNode = new Node(nums[i], 1);
                valueNodes.put(nums[i], newNode);
                maxHeap.add(newNode);
            }
        }

        for (int i = k - 1; i < nums.length; ++i) {
            while (!maxHeap.isEmpty() && maxHeap.peek().isCountZero()) {
                valueNodes.remove(maxHeap.poll().getValue());
            }

            if (valueNodes.containsKey(nums[i])) {
                valueNodes.get(nums[i]).incrementCount();
            } else {
                Node newNode = new Node(nums[i], 1);
                valueNodes.put(nums[i], newNode);
                maxHeap.add(newNode);
            }

            res[i - k + 1] = maxHeap.peek().getValue();
            for (Map.Entry<Integer, Node> entry : valueNodes.entrySet()) {
                System.out.print("{Key: " + entry.getKey() + ", Value: " + entry.getValue().getCount() + "}, ");
            }
            System.out.println('\n');

            valueNodes.get(nums[i - k + 1]).decrementCount();
        }

        return res;
    }
}
