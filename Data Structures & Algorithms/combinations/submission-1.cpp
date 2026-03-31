class Solution {
    vector<int> subset;
    vector<vector<int>> res;
    int size;
    void dfs(int start, int k) {
        if (k == 0) {
            res.push_back(vector<int>(subset));
            return;
        }

        for (int i = start; i < size + 2 - k; ++i) {
            subset.push_back(i);
            dfs(i + 1, k - 1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        subset = vector<int>();
        res = vector<vector<int>>();
        size = n;
        dfs(1, k);

        return res;
    }
};