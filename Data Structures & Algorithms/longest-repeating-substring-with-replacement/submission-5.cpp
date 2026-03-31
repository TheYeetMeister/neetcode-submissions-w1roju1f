class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charCounts;
        
        int maxCount = 0;

        int left = 0, maxFrequency = 0;

        for (int right = 0; right < s.size(); ++right) {
            ++charCounts[s[right]];
            maxFrequency = max(maxFrequency, charCounts[s[right]]);

            while ((right - left + 1 ) - maxFrequency > k) {
                --charCounts[s[left]];
                ++left;
            }

            maxCount = max(maxCount, right - left + 1);
        }

        return maxCount;
    }
};
