class Solution {
    string add(string& num1, string& num2) {
        if (num1.size() > num2.size()) {
            num1.swap(num2);
        }
        
        string res = "";
        int curr = 0;

        int i = 0;
        for (;i < num1.size(); ++i) {
            curr += num1[num1.size() - i - 1] - '0';
            curr += num2[num2.size() - i - 1] - '0';
            res.push_back(curr % 10 + '0');
            curr /= 10;
        }

        for (; i < num2.size(); ++i) {
            curr += num2[num2.size() - i - 1] - '0';
            res.push_back(curr % 10 + '0');
            curr /= 10;
        }

        if (curr) {
            res.push_back('1');
        }

        reverse(res.begin(), res.end());

        return res;
    }
    
    string multiplyOne(string& numStr, char single, int numStart) {
        int multiple = single - '0';
        if (!multiple) return "0";

        string res(numStart, '0');

        int curr = 0;
        for (int i = 0; i < numStr.size(); ++i) {
            curr += (numStr[numStr.size() - i - 1] - '0') * multiple;
            res.push_back(curr % 10 + '0');
            curr /= 10;
        }

        while (curr) {
            res.push_back(curr % 10 + '0');
            curr /= 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }

public:
    string multiply(string num1, string num2) {
        if (num1.size() < num2.size()) {
            num1.swap(num2);
        }

        string curr = "0";

        for (int i = 0; i < num2.size(); ++i) {
            string copy = multiplyOne(num1, num2[num2.size() - i - 1], i);
            curr = add(curr, copy);
        }

        return curr;
    }
};
