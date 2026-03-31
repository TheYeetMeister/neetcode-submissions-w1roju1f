class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) {
            return false;
        }

        unordered_map<int, unsigned> counts;
        for (int num: hand) {
            ++counts[num];
        }

        for (int num: hand) {
            if (!counts[num]) {
                continue;
            }

            int start = num;
            while(counts[start - 1]) {
                start = start - 1;
            }
            for (int i = 0; i < groupSize; ++i) {
                if (!counts[start]) return false;
                --counts[start];
                ++start;
            }
        }
        return true;
    }
};
