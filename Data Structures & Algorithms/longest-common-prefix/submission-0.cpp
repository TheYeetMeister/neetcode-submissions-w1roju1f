class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longestPrefix = "";
        for (int i = 0; i < strs[0].length(); ++i) {
            bool sameLetters = true;
            char letter = strs[0][i];

            for (string& word: strs) {
                if (letter != word[i]) {
                    sameLetters = false;
                    break;
                }
            }

            if (!sameLetters) {
                break;
            }

            longestPrefix += letter;

        }

        return longestPrefix;
    }
};