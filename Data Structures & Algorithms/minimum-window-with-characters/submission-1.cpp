class Solution {
public:
    const int fullPossibleMatches = 52;
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }

        unordered_map<char, int> tCharCount{};
        int matchesAndOver = fullPossibleMatches;

        for (char c: t) {
            if (!tCharCount[c]) {
                --matchesAndOver;
            }

            ++tCharCount[c];
        }

        int left = 0;
        unsigned int minCount = UINT_MAX;
        int minLeft = 0;

        unordered_map<char, int> sCharCount{};

        for (int right = 0; right < s.size(); ++right) {
            ++sCharCount[s[right]];

            if (sCharCount[s[right]] == tCharCount[s[right]]) {
                ++matchesAndOver;
            }

            while (matchesAndOver == fullPossibleMatches) {
                if (right - left + 1 < minCount) {
                    minCount = right - left + 1;
                    minLeft = left;
                }
                
                if (sCharCount[s[left]] == tCharCount[s[left]]) {
                    --matchesAndOver;
                }
                --sCharCount[s[left]];
                ++left;
            }
        }

        if (minCount != UINT_MAX) {
            return s.substr(minLeft, minCount);
        } else {
            return "";
        }
    }
};
