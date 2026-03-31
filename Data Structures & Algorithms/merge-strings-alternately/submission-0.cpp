class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int n = word1.size();
        int m = word2.size();
        res.reserve(n + m);

        int i = 0;
        int j = 0;

        while (i < n && j < m) {
            res.push_back(word1[i++]);
            res.push_back(word2[j++]);
        }

        while (i < n) {
            res.push_back(word1[i++]);
        }

        while (j < m) {
            res.push_back(word2[j++]);
        }

        return res;
    }
};