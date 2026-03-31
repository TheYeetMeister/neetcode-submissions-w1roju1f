class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tCharCount{};
        int matchesAndOver = 26;

        for (char c: t) {
            if (!tCharCount[c]) {
                --matchesAndOver;
            }

            ++tCharCount[c];
        }

        int left = 0;
        int minCount = INT_MAX;
        string substr = "";

        unordered_map<char, int> sCharCount{};

        for (int right = 0; right < s.size(); ++right) {
            ++sCharCount[s[right]];

            if (sCharCount[s[right]] == tCharCount[s[right]]) {
                ++matchesAndOver;
            }

            while (matchesAndOver == 26) {
                if (right - left + 1 < minCount) {
                    minCount = right - left + 1;
                    substr = s.substr(left, minCount);
                }
                
                if (sCharCount[s[left]] == tCharCount[s[left]]) {
                    --matchesAndOver;
                }
                --sCharCount[s[left]];
                ++left;
            }
        }

        return substr;
    }
};
