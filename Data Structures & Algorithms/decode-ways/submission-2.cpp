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
        vector<int> dp(s.size() + 1, 0);  

        dp[0] = 1;

        int i = 0;
        for (; i < s.size() - 1; ++i) {
            if (s[i] == '0') {
                continue;
            }

            int currNum = s[i] - '0';

            dp[i + 1] += dp[i];

            if (currNum == 1 || 
                currNum == 2 && s[i + 1] - '0' < 7) {
                dp[i + 2] += dp[i];
            }
        }

        if (s[i] != '0') {
            dp[i + 1] += dp[i];
        }

        return dp.back();
    }
};
