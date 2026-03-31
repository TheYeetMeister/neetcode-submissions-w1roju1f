class MedianFinder {
    PriorityQueue<Integer> rightMinHeap;
    PriorityQueue<Integer> leftMaxHeap;

    public MedianFinder() {
        rightMinHeap = new PriorityQueue<Integer>();
        leftMaxHeap = new PriorityQueue<Integer>(Comparator.reverseOrder());
    }

    public boolean isLeftSideLarger() {
        return leftMaxHeap.size() > rightMinHeap.size();
    }

    public boolean isRightSideLarger() {
        return leftMaxHeap.size() < rightMinHeap.size();
    }

    public int size() {
        return rightMinHeap.size() + leftMaxHeap.size();
    }
    
    public void addNum(int num) {
        double median = findMedian();

        if (num > median) {
            if (isRightSideLarger()) {
                leftMaxHeap.add(rightMinHeap.poll());
            }
            rightMinHeap.add(num);
        } else {
            if (isLeftSideLarger()) {
                rightMinHeap.add(leftMaxHeap.poll());
            }
            leftMaxHeap.add(num);
        }
    }
    
    public double findMedian() {
        if (size() == 0) {
            return 0;
        } else if (size() % 2 == 0) {
            return (double) (rightMinHeap.peek() + leftMaxHeap.peek()) / 2;
        } else if (isRightSideLarger()) {
            return rightMinHeap.peek();
        } else {
            return leftMaxHeap.peek();
        }
    }
}
