class Solution {
public:
    void backtracking(int left, int right, int n, string& stack, vector<string>& result) {
        if (right == left && left == n) {
            result.push_back(stack);
            return;
        }
        
        if (left < n) {
            stack.push_back('(');
            backtracking(left + 1, right, n, stack, result);
            stack.pop_back();
        }

        if (left > right) {
            stack.push_back(')');
            backtracking(left, right + 1, n, stack, result);
            stack.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result{};

        string stack = "";

        backtracking(0, 0, n, stack, result);

        return result;
    }
};
