class Solution {
    private double calDistance(int[] point) {
        return Math.sqrt(Math.pow(point[0], 2) + Math.pow(point[1], 2));
    }

    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<double[]> maxHeap = new PriorityQueue<>(
            Comparator.comparingDouble((double[] a) ->  a[0]).reversed()
        );

        for (int i = 0; i < points.length; ++i) {
            maxHeap.add(new double[]{calDistance(points[i]), i});

            if (maxHeap.size() > k) {
                maxHeap.poll();
            }
        }

        int res[][] = new int[k][2];

        for (int i = 0; i < k; ++i) {
            res[i] = points[(int) maxHeap.poll()[1]];
        }

        return res;
    }
}
