class Solution {
    int res;
    int n ;
    vector<bool> col;
    vector<bool> diagRight;
    vector<bool> diagLeft;

    int calDiagRight(int i, int j) {
        return n + i - j - 1;
    }

    int calDiagLeft(int i, int j) {
        return i + j;
    }

    void dfs(int i) {
        if (i == n) {
            ++res;
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (col[j] &&
                diagRight[calDiagRight(i, j)] &&
                diagLeft[calDiagLeft(i, j)]
                ) {
                    col[j] = false;
                    diagRight[calDiagRight(i, j)] = false;
                    diagLeft[calDiagLeft(i, j)] = false;

                    dfs(i + 1);

                    col[j] = true;
                    diagRight[calDiagRight(i, j)] = true;
                    diagLeft[calDiagLeft(i, j)] = true;
            }
        }
    }
public:
    int totalNQueens(int n) {
        res = 0;
        this->n = n;

        col = vector<bool>(n, true);
        diagRight = vector<bool>(2 * n, true);
        diagLeft = vector<bool>(2 * n, true);

        dfs(0);
        return res;
    }
};