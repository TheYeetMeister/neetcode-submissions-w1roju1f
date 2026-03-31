class Solution {
    int backtrack(string &s, int i) {
        if (i >= s.size()) {
            return 1;
        }

        if (s[i] == '0') {
            return 0;
        }

        int c = s[i] - '0';

        int skip = 0;
        if (i < s.size() - 1 && (
                c == 1 ||
                c == 2 && s[i + 1] - '0' < 7
            )) {
            skip = backtrack(s, i + 2);
        }

        int take = backtrack(s, i + 1);

        return take + skip;
    }
public:
    int numDecodings(string s) {
        return backtrack(s, 0);
    }
};
