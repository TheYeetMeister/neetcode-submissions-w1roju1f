class Solution {
public:
    bool isAnagram(string s, string t) {
        unsigned sLetterCount[26] = {};
        unsigned tLetterCount[26] = {};

        for (unsigned i = 0; i < s.size(); ++i) {
            ++sLetterCount[s[i] - 'a'];
        }

        for (unsigned i = 0; i < t.size(); ++i) {
            ++tLetterCount[t[i] - 'a'];
        }

        for (unsigned i = 0; i < 26; ++i) {
            if (sLetterCount[i] != tLetterCount[i]) {
                return false;
            }
        }
        return true;
    }
};
