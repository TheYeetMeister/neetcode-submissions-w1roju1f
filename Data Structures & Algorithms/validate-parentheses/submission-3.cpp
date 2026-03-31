class Solution {
public:
    bool isValid(string s) {
        stack<char> parens;

        for (char i: s) {
            if (i == '(' || i == '[' || i == '{') {
                parens.push(i);
            } else {
                if (parens.empty()) {
                    return false;
                }

                switch (i) {
                    case ')':
                        if (parens.top() != '(') {
                            return false;
                        }
                        parens.pop();
                        break;
                    case ']':
                        if (parens.top() != '[') {
                            return false;
                        }
                        parens.pop();
                        break;
                    case '}':
                        if (parens.top() != '{') {
                            return false;
                        }
                        parens.pop();
                        break;
                    default:
                        cout << "error" << endl;
                }
            }
        }

        return parens.empty();
    }
};
