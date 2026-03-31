class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int charCnt[26] = {0};
        for (char a: tasks) {
            ++charCnt[a - 'A'];
        }

        priority_queue<int> maxHeap;
        for (int cnt: charCnt) {
            if (cnt) {
                maxHeap.push(cnt);
            }
        }

        int time = 0;
        queue<pair<int, char>> waitQueue;

        while (!maxHeap.empty() || !waitQueue.empty()) {
            ++time;
            
            if (maxHeap.empty()) {
                time = waitQueue.front().second;
            } else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();

                if (cnt) {
                    waitQueue.push({cnt, time + n});
                }
            }

            if (!waitQueue.empty() && waitQueue.front().second == time) {
                maxHeap.push(waitQueue.front().first);
                waitQueue.pop();
            }
        }

        return time;
    }
};
