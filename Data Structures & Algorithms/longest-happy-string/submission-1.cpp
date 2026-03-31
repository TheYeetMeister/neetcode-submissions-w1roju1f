class Solution {
    void addCharNum(priority_queue<vector<int>>& maxHeap, int num, char letter) {
        if (num > 0) {
            maxHeap.push({num, letter});
        }
    }
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        priority_queue<vector<int>> maxHeap;

        addCharNum(maxHeap, a, 'a');
        addCharNum(maxHeap, b, 'b');
        addCharNum(maxHeap, c, 'c');

        vector<int> prev;
        int prevInt = 0;

        while (maxHeap.size() > 0) {
            vector<int> temp = maxHeap.top();
            maxHeap.pop();
            if (temp != prev) {
                if (prevInt == 2 && prev[0] > 0) {
                    maxHeap.push(prev);
                }
                prevInt = 1;
            } else {
                ++prevInt;
            }

            prev = temp;
            res.push_back(prev[1]);
            --prev[0];

            if (prevInt != 2 && prev[0] > 0) {
                maxHeap.push(prev);
            }
        }

        return res;
    }
};