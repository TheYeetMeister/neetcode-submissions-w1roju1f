class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        unordered_map<string, function<int(int, int)>> operations = {
            {"+", [](int a, int b) {return a + b;}},
            {"-", [](int a, int b) {return a - b;}},
            {"*", [](int a, int b) {return a * b;}},
            {"/", [](int a, int b) {return a / b;}}
        };

        for (string i: tokens) {
            if (operations.find(i) != operations.end()) {
                int numRight = nums.top();
                nums.pop();
                int numLeft = nums.top();
                nums.pop();

                int result = operations[i](numLeft, numRight);
                nums.push(result);
            } else {
                nums.push(stoi(i));
            }
        }

        return nums.top();
    }
};
