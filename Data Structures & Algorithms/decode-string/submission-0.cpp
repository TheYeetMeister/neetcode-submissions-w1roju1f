class Solution {
    bool isNum(char s) {
        return s <= '9' && s >= '0';
    }

    string getWord(string& s, int& i) {
        string word = "";

        --i;
        while (s[i] != '[') {
            if (s[i] == ']') {
                word += getWord(s, i);
            } else {
                word += s[i];
                --i;
            }
        }
        --i;

        string numStr = "";
        for (;i >= 0 && isNum(s[i]); --i) {
            numStr += s[i];
        }
        reverse(numStr.begin(), numStr.end());

        int num = stoi(numStr);

        string res = "";

        for (int j = 0; j < num; ++j) {
            res += word;
        }

        return res;
    }
public:
    string decodeString(string s) {
        string res = "";

        for (int i = s.size() - 1; i >= 0;) {
            if (s[i] == ']') {
                res += getWord(s, i);
            } else {
                res += s[i];
                --i;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};