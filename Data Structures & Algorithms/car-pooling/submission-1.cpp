class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pickUpMinHeap;

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > dropOffMinHeap;
        int currTime = 0;
        int currSize = 0;

        for (vector<int>& trip: trips) {
            pickUpMinHeap.push({trip[1], trip[2], trip[0]});
        }

        while (!pickUpMinHeap.empty()) {
            vector<int> top = pickUpMinHeap.top();
            pickUpMinHeap.pop();

            currTime = top[0];
            currSize += top[2];

            dropOffMinHeap.push({top[1], top[2]});

            while (!dropOffMinHeap.empty() && dropOffMinHeap.top()[0] <= currTime) {
                currSize -= dropOffMinHeap.top()[1];
                dropOffMinHeap.pop();
            }

            if (currSize > capacity) {
                return false;
            }
        }

        return true;
    }
};