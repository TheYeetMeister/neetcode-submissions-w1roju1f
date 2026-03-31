class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> characters {};
        int maxCount = 0;

        int i = 0;
        int j = 0;

        while (j < s.size()) {
            if (characters.find(s[j]) == characters.end()) {
                characters.insert(s[j]);
                ++j;
                maxCount = max(maxCount, j - i);
            } else {
                characters.erase(s[i]);
                ++i;
            }
        }
        maxCount = max(maxCount, j - i);

        return maxCount;
    }
};
