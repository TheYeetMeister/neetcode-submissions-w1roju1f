class Solution {
    int moves(string& word1, string& word2, int i, int j) {
        if (i == word1.size() && j == word2.size()) {
            return 0;
        } else if (i == word1.size()) {
            return word2.size() - j;
        } else if (j == word2.size()) {
            return word1.size() - i;
        }

        if (word1[i] == word2[j]) {
            return moves(word1, word2, i + 1, j + 1);
        } else {
            int minNumChan = 1 + moves(word1, word2, i + 1, j + 1);
            minNumChan = min(minNumChan, 1 + moves(word1, word2, i, j + 1));
            minNumChan = min(minNumChan, 1 + moves(word1, word2, i + 1, j));

            return minNumChan;
        }
    }
public:
    int minDistance(string word1, string word2) {
        return moves(word1, word2, 0, 0);
    }
};
