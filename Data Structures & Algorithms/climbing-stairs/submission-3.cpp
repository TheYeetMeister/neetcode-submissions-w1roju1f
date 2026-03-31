class Solution {
public:
    int climbStairs(int n) {
        vector<int> combToPos(n + 1, 0);
        combToPos[0] = 1;

        int i = 0;
        for (; i < n - 1; ++i) {
            combToPos[i + 2] += combToPos[i];
            combToPos[i + 1] += combToPos[i];
        }

        for (; i < n; ++i) {
            combToPos[i + 1] += combToPos[i];
        }

        return combToPos.back();
    }
};
