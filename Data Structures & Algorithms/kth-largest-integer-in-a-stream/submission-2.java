class KthLargest {
    int k;
    PriorityQueue<Integer> buf;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        buf = new PriorityQueue<>();

        for (int i: nums) {
            this.add(i);
        }
    }
    
    public int add(int val) {
        buf.add(val);
        if (buf.size() > k) {
            buf.poll();
        }

        return buf.peek();
    }
}
