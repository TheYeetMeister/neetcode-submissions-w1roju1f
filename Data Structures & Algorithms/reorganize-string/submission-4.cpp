class Solution {
public:
    string reorganizeString(string s) {
        vector<int> frequencyList(26, 0);

        for (char c: s) {
            ++frequencyList[c - 'a'];
        }

        priority_queue<
            vector<int>
        > maxHeap;

        for (int i = 0; i < 26; ++i) {
            if (frequencyList[i] > 0) {
                maxHeap.push({frequencyList[i], i});
            }
        }

        vector<int> prev = {0, 1};
        string res = "";

        while (!maxHeap.empty()) {
            vector<int> top = maxHeap.top();
            maxHeap.pop();
            --top[0];

            res.push_back(top[1] + 'a');

            if (prev[0] > 0) {
                maxHeap.push(prev);
            }

            prev = top;
        }

        return (prev[0] == 0) ? res: "";
    }
};