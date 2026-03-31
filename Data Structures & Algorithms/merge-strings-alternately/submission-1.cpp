class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int i = 0, n = word1.size(), m = word2.size();
        res.reserve(n + m);

        while (i < n && i < m) {
            res.push_back(word1[i]);
            res.push_back(word2[i++]);
        }

        while (i < n) {
            res.push_back(word1[i++]);
        }

        while (i < m) {
            res.push_back(word2[i++]);
        }

        return res;
    }
};