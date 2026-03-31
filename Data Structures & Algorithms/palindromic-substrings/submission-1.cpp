class Solution {
    int palinCount(string& s, int i, int j) {
        int count = 0;

        for (;i >= 0 && j < s.size() && s[i] == s[j];
            --i, ++j) {
                ++count;
        }

        return count;
    }
public:
    int countSubstrings(string s) {
        if (s.size() == 0) {
            return 0;
        }
        
        int totalCnt = 1;

        for (int i = 1; i < s.size(); ++i) {
            totalCnt += palinCount(s, i, i);
            totalCnt += palinCount(s, i - 1, i);
        }

        return totalCnt;
    }
};
