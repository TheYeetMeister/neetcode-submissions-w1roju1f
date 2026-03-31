class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1Count{};

        for (char c: s1) {
            ++s1Count[c];
        }

        
        for (int i = 0; i < s2.size() - s1.size() + 1; ++i) {
            unordered_map<char, int> s2Count{};
            int j = 0;

            for (; j < s1.size(); ++j) {
                ++s2Count[s2[i + j]];

                if (s2Count[s2[i + j]] > s1Count[s2[i + j]]) {
                    break;
                }
            }

            if (j == s1.size()) {
                return true;
            }
        }
        return false;
    }
};
