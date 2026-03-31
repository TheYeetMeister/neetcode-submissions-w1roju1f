class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> indegrees(26, 0);

        int charCount = 0;
        vector<bool> possChars(26, false);

        for (int i = 0; i < words.size() - 1; ++i) {
            int w1c = 0;
            int w2c = 0;
            bool firstDif = false;

            for (;w1c < words[i].size() && 
                w2c < words[i + 1].size(); ++w1c, ++w2c) {
                    if (words[i][w1c] != words[i + 1][w2c] && !firstDif) {
                        adj[words[i][w1c] - 'a'].push_back(words[i + 1][w2c] - 'a');
                        ++indegrees[words[i + 1][w2c] - 'a'];

                        firstDif = true;
                    }
                    
                    if (!possChars[words[i][w1c] - 'a']) {
                        possChars[words[i][w1c] - 'a'] = true;
                        ++charCount;
                    }

                    if (!possChars[words[i + 1][w2c] - 'a']) {
                        possChars[words[i + 1][w2c] - 'a'] = true;
                        ++charCount;
                    }
            }
            
            if (!firstDif && w1c < words[i].size()) {
                return "";
            }

            for (; w2c < words[i + 1].size(); ++w2c) {
                if (!possChars[words[i + 1][w2c] - 'a']) {
                    possChars[words[i + 1][w2c] - 'a'] = true;
                    ++charCount;
                }
            }
        }

        for (char i: words.back()) {
            if (!possChars[i - 'a']) {
                possChars[i - 'a'] = true;
                ++charCount;
            }
        }

        queue<int> frontier;
        for (int i = 0; i < 26; ++i) {
            if (possChars[i] && indegrees[i] == 0) {
                frontier.push(i);
            }
        }

        string res = "";

        while (!frontier.empty()) {
            int top = frontier.front();
            frontier.pop();

            res.push_back(top + 'a');

            for (int i: adj[top]) {
                --indegrees[i];

                if (indegrees[i] == 0) {
                    frontier.push(i);
                }
            }
        }

        return (res.size() == charCount) ? res: "";
    }
};
