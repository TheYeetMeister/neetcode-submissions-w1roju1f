class Solution {
    int dfs(string& s, string& t, int i, int j) {
        if (t.size() == j) {
            return 1;
        }

        if (s.size() == i) {
            return 0;
        }

        int cnt = 0;

        if (s[i] == t[j]) {
            cnt += dfs(s, t, i + 1, j + 1);
        }
        cnt += dfs(s, t, i + 1, j);

        return cnt;
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 0; i <= s.size(); ++i) {
            dp[i][t.size()] = 1;
        }
        
        for(int i = s.size() - 1; i >= 0; --i) {
            for (int j = t.size() - 1; j >= 0; --j) {
                if (s[i] == t[j]) {
                    dp[i][j] += dp[i + 1][j + 1];
                }
                dp[i][j] += dp[i + 1][j];
            }
        }

        return dp[0][0];
    }
};
