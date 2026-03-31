class Solution {
    int daysToShip(const vector<int>& weights, int truckWeight) {
        int truckNum = 1;
        int currWeight = 0;

        for (int weight: weights) {
            if (currWeight > truckWeight - weight) {
                ++truckNum;
                currWeight = weight;
            } else {
                currWeight += weight;
            }
        }

        return truckNum;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;

        for (int weight: weights) {
            l = max(l, weight);
            r += weight;
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int transportTime = daysToShip(weights, mid);

            if (transportTime > days) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
};