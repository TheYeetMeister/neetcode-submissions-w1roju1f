class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftParenInd;
        stack<int> starInd;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (!leftParenInd.empty()) {
                    leftParenInd.pop();
                } else if (!starInd.empty()) {
                    starInd.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '(') {
                leftParenInd.push(i);
            } else {
                starInd.push(i);
            }
        }

        while (!leftParenInd.empty()) {
            if (starInd.empty() || starInd.top() < leftParenInd.top()) {
                return false;
            }
            starInd.pop();
            leftParenInd.pop();
        }

        return true;
    }
};
