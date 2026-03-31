class Solution {
    private double calTimeToEnd(int target, int position, int speed) {
        return (double) (target - position) / speed;
    }

    public int carFleet(int target, int[] position, int[] speed) {
        int[][] cars = new int[position.length][2];

        for (int i = 0; i < position.length; ++i) {
            cars[i][0] = position[i];
            cars[i][1] = speed[i];
        }

        Arrays.sort(cars, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return Integer.compare(b[0], a[0]);
            }
        });

        double longestEndTime = 0;
        int cnt = 0;

        for (int i = 0; i < cars.length; ++i) {
            double timeToEnd = calTimeToEnd(target, cars[i][0], cars[i][1]);
            if (timeToEnd > longestEndTime) {
                ++cnt;
                longestEndTime = timeToEnd;
            }
        }

        return cnt;
    }
}
