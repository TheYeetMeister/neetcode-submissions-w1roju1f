class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1Count{};

        for (char c: s1) {
            ++s1Count[c];
        }

        int left = 0;
        int right = 0;

        unordered_map<char, int> s2Count{};

        for (; right < s2.size(); ++right) {
            ++s2Count[s2[right]];

            for (;s2Count[s2[right]] > s1Count[s2[right]]; ++left) {
                --s2Count[s2[left]];
            }

            if (right - left == s1.size() - 1) {
                return true;
            }
        }
        
        return false;
    }
};
