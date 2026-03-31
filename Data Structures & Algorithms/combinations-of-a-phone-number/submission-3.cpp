class Solution {
    string numToLet[8] = {
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    void backtracking(const int i, string& digits, 
                    vector<string>& res, string& currStr) {
        if (i >= digits.size()) {
            res.push_back(currStr);
            return;
        }

        for (char j: numToLet[digits[i] - '2']) {
            currStr.push_back(j);
            backtracking(i + 1, digits, res, currStr);
            currStr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return {};
        }

        string currStr = "";
        vector<string> res{};

        backtracking(0, digits, res, currStr);

        return res;
    }
};
