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
        return dfs(s, t, 0, 0);
    }
};
