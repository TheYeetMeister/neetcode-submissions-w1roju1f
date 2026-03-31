class Solution {
    const int allowedCharDeletion = 1;

    bool isAlphaNumeric(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }

    bool checkPalindrome(string s, int l, int r, int charChangeDeep) {
        if (charChangeDeep > allowedCharDeletion) {
            return false;
        }

        while (l < r) {
            if (!isAlphaNumeric(s[l])) {
                ++l;
                continue;
            }

            if (!isAlphaNumeric(s[r])) {
                --r;
                continue;
            }

            if (s[l] != s[r]) {
                return checkPalindrome(s, l + 1, r, charChangeDeep + 1) ||
                        checkPalindrome(s, l, r - 1, charChangeDeep + 1);
            }

            ++l;
            --r;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        return checkPalindrome(s, 0, s.size() - 1, 0);
    }
};