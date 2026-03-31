class Solution {
    private int hoursToEat(int[] piles, int bph) {
        int hours = 0;

        for (int pile: piles) {
            hours += pile / bph + (pile % bph > 0? 1: 0);
        }

        return hours;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int l = 1, r = 1;

        for (int pile: piles) {
            r = Math.max(pile, r);
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int time = hoursToEat(piles, mid);

            if (time > h) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
}
