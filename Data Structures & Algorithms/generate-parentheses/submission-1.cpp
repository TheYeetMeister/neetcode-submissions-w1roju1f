class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> solution(n + 1);
        solution[0] = {""};

        for (int k = 0; k <= n; ++k) {
            for (int i = 0; i < k; ++i) {
                for (const string& left: solution[i]) {
                    for (const string& right: solution[k - i - 1]) {
                        solution[k].push_back("(" + left + ")" + right);
                    }
                }
            }
        }
        return solution[n];
    }
};
