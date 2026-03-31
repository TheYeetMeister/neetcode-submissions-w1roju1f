class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>> maxHeap;

        int lowerChar[26] = {0};

        for (char a: tasks) {
            ++lowerChar[a - 'A'];
        }

        unordered_set<char> undoneTasks;
        for (int i = 0; i < 26; ++i) {
            if (lowerChar[i]) {
                maxHeap.push({lowerChar[i], i + 'A'});
                undoneTasks.insert(i + 'A');
            }
        }

        queue<pair<int, char>> waitQueue;
        int count = 0;

        while (!undoneTasks.empty()) {
            ++count;
            
            if (!maxHeap.empty()) {
                pair<int, char> doneTask = maxHeap.top();
                maxHeap.pop();

                if (!--doneTask.first) {
                    undoneTasks.erase(doneTask.second);
                }
                waitQueue.push(doneTask);
            } else {
                waitQueue.push({0, 'A'});
            }

            if (waitQueue.size() > n) {
                pair<int, char> ready = waitQueue.front();
                waitQueue.pop();

                if (ready.first) {
                    maxHeap.push(ready);
                }
            }
        }

        return count;
    }
};
