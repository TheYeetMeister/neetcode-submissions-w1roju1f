class Solution {
    bool isOneStep(string x, string y) {
        bool change = false;
        for (int i = 0, j = 0;i < x.size() && j < y.size(); ++i, ++j) {
            if (x[i] != y[i]) {
                if (change) {
                    return false;
                }
                change = true;
            }
        }

        return change;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        unordered_set<string> visited;

        queue<string> q;
        visited.insert(beginWord);
        q.push(beginWord);

        int walk = 0;
        while(!q.empty()) {
            int size = q.size();
            ++walk;
            for (int i = 0; i < size; ++i) {
                string word = q.front();
                q.pop();

                for (string& s: wordList) {
                    if (visited.find(s) == visited.end() && isOneStep(word, s)) {
                        if (s == endWord) {
                            return walk + 1;
                        }
                    
                        q.push(s);
                        visited.insert(s);
                    }
                }
            }
        }

        return 0;
    }
};
