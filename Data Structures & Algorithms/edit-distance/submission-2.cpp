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
        vector<vector<unsigned>> dp(word1.size() + 1, vector<unsigned>(word2.size() + 1, UINT_MAX));

        for (int i = 0; i < word1.size(); ++i) {
            dp[i][word2.size()] = word1.size() - i;
        }
        for (int j = 0; j < word2.size(); ++j) {
            dp[word1.size()][j] = word2.size() - j;
        }
        dp[word1.size()][word2.size()] = 0;

        for (int i = word1.size() - 1; i >= 0; --i) {
            for (int j = word2.size() - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]);
                }
                unsigned minChange = min(dp[i + 1][j], dp[i][j + 1]);
                minChange = min(dp[i + 1][j + 1], minChange);

                dp[i][j] = min(dp[i][j], minChange + 1);
            }
        }

        return dp[0][0];
    }
};
