class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> charEndInd;

        for (int i = 0; i < s.size(); ++i) {
            charEndInd[s[i]] = i;
        }

        int end = 0, lastPart = -1;
        vector<int> res;

        for (int i = 0; i < s.size(); ++i) {
            if (charEndInd[s[i]] > end) {
                end = charEndInd[s[i]];
            }
            
            if (i == end) {
                res.push_back(i - lastPart);
                lastPart = i;
            }
        }

        return res;
    }
};
