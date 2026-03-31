class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        res.reserve(digits.size());

        int carry = 1;

        for (int i = 0; i < digits.size(); ++i) {
            res.push_back((digits[digits.size() - i - 1] + carry) % 10);
            carry = (digits[digits.size() - i - 1] + carry) / 10;
        }

        if (carry) res.push_back(carry);

        reverse(res.begin(), res.end());

        return res;
    }
};
