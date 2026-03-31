class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxEatingRate = 0;

        for (int pile: piles) {
            maxEatingRate = max(pile, maxEatingRate);
        }

        int minEatingRate = 1;

        while (maxEatingRate > minEatingRate) {
            int midEatingRate = (maxEatingRate + minEatingRate) / 2;

            int fullEatingTime = 0;

            for (int pile: piles) {
                fullEatingTime += (pile + midEatingRate - 1) / midEatingRate;
            }

            cout << fullEatingTime << "hours" << endl;
            cout << midEatingRate << "bn/h" << endl;

            if (fullEatingTime > h) {
                minEatingRate = midEatingRate + 1;
            } else {
                maxEatingRate = midEatingRate;
            }
        }

        return minEatingRate;
    }
};
