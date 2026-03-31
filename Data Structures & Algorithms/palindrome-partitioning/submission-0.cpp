class Solution {
    bool isPalindrome(string& s, int start, int end) {
        while (end > start) {
            if (s[end] != s[start]) {
                return false;
            }
            --end;
            ++start;
        }
        return true;
    }

    void backtracking(string& s, int start, vector<vector<string>>& res, vector<string>& currVec) {
        if (start == s.size()) {
            res.push_back(currVec);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                currVec.push_back(s.substr(start, end - start + 1));
                backtracking(s, end + 1, res, currVec);
                currVec.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res{};
        vector<string> currVec{};

        backtracking(s, 0, res, currVec);

        return res;
    }
};
