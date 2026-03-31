class Solution {
    int longestPal(string& s, int& i, int& j) {
        for (;i >= 0 && j < s.size() && s[i] == s[j]; --i, ++j);

        ++i;
        --j;
    }
public:
    string longestPalindrome(string s) {
        int resBeg = 0;
        int resEnd = 0;
        for (int i = 1; i < s.size(); ++i) {
            int k = i;
            int m = i;
            longestPal(s, k, m);

            if (resEnd - resBeg < m - k) {
                resBeg = k;
                resEnd = m;
            }

            k = i;
            m = i - 1;
            longestPal(s, k, m);

            if (resEnd - resBeg < m - k) {
                resBeg = k;
                resEnd = m;
            }
        }

        return s.substr(resBeg, resEnd - resBeg + 1);
    }
};
