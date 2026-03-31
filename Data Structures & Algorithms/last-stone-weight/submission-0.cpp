class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (int stone: stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top();
            maxHeap.pop();

            int stone2 = maxHeap.top();
            maxHeap.pop();

            int value = abs(stone1 - stone2);

            if (value) {
                maxHeap.push(value);
            }
        }

        if (maxHeap.size()) {
            return maxHeap.top();
        } else {
            return 0;
        }
    }
};
