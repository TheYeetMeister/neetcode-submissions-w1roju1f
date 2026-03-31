class Solution {
    int findNextLargest(vector<int>& hand, int i) {
        if (i == -1) {
            i = 0;
            for(; hand[i] == -1; ++i);
            return i;
        }

        for (int j = i + 1; j < hand.size(); ++j) {
            if (hand[j] == hand[i] + 1) {
                return j;
            }
        }

        return -1;
    }

public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) {
            return false;
        }

        vector<int> sortedHand = hand;
        sort(sortedHand.begin(), sortedHand.end());
        unsigned groups = hand.size() / groupSize;

        for (int i = 0; i < groups; ++i) {
            int first = findNextLargest(sortedHand, -1);
            for (int j = 1; j < groupSize; ++j) {
                int next = findNextLargest(sortedHand, first);

                if (next == -1) {
                    return false;
                }
                sortedHand[first] = -1;
                first = next;
            }
            sortedHand[first] = -1;
        }

        return true;
    }
};
