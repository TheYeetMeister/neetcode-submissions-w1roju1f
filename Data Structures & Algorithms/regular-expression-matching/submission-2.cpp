class Solution {
    bool dfs(string &s, string &p, int i, int j) {
        for (; i >= 0 && j >= 0 && (s[i] == p[j] || p[j] == '.'); --i, --j);

        if (p[j] == '*') {
            char prec = p[j - 1];

            for (; i >= 0 && (prec == '.' || s[i] == prec); --i) {
                if (dfs(s, p, i, j - 2)) {
                    return true;
                }
            }
            if (dfs(s, p, i, j - 2)) {
                return true;
            }
        }

        if (i == -1 || j == -1) {
            return i == -1 && j == -1;
        }

        return false;
    }
public:
    bool isMatch(string s, string p) {
        return dfs(s, p, s.size() - 1, p.size() - 1);
    }
};
