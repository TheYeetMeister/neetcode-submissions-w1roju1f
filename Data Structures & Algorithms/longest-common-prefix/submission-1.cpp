class Solution {
public:
    bool isAllSameLetter(vector<string>& strs, int index) {
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i - 1][index] != strs[i][index]) {
                return false;
            }
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        unsigned minLength = UINT_MAX;
        for (string& s: strs) {
            minLength = min(minLength, static_cast<unsigned>(s.length()));
        }

        int i = 0;
        for (; i < minLength; ++i) {
            if (!isAllSameLetter(strs, i)) {
                break;
            }
        }

        return strs[0].substr(0, i);
    }
};