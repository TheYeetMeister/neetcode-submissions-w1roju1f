class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxHeap = 
            new PriorityQueue<>(Comparator.reverseOrder());

        for (int rock: stones) {
            maxHeap.add(rock);
        }

        while (maxHeap.size() > 1) {
            int rockA = maxHeap.poll();
            int rockB = maxHeap.poll();

            int diff = rockA - rockB;

            if (diff > 0) {
                maxHeap.add(diff);
            }
        }

        return (maxHeap.isEmpty())? 0: maxHeap.peek();
    }
}
