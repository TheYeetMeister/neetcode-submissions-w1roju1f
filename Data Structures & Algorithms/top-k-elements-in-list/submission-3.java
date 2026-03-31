class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> numCounts = new HashMap<>();
        for (int i: nums) {
            numCounts.put(i, 1 + numCounts.getOrDefault(i, 0));
        }

        PriorityQueue<int[]> heap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (Map.Entry<Integer, Integer> entry: numCounts.entrySet()) {
            heap.offer(new int[]{entry.getValue(), entry.getKey()});
            if (heap.size() > k) {
                heap.poll();
            }
        }
        
        int[] ans = new int[k];

        for (int i = 0; i < k; ++i) {
            ans[i] = heap.poll()[1];
        }

        return ans;
    }
}
