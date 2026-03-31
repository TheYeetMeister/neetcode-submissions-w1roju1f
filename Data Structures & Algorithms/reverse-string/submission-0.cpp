class Solution {
    void swapValues(vector<char>& s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
public:
    void reverseString(vector<char>& s) {
        unsigned n = s.size();

        for (int i = 0; i < n / 2; ++i) {
            swapValues(s, i, n - i - 1);
        }
    }
};