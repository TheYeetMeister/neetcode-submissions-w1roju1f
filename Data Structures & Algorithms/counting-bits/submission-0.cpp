class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);

        for (int i = 0; i <= n; ++i) {
            int val = i;
            int count = 0;

            for (;val; val = val & (val - 1), ++count);
            res[i] = count;
        }

        return res;
    }
};
