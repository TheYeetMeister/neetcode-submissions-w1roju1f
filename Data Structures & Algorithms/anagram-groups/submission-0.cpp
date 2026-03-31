#include <unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> countList;

        for (string i: strs) {
            int letterCount[26] = {};

            for (char j: i) {
                ++letterCount[j - 'a'];
            }

            string H(i.size(), '*');
            unsigned count = 0;

            for (int k = 0; k < 26; ++k) {
                for (int l = 0; l < letterCount[k]; ++l, ++count) {
                    H[count] = k + 'a';
                }
            }

            auto find = countList.find(H);
            if (find != countList.end()) {
                find->second.push_back(i);
            } else {
                countList[H] = vector<string>{i};
            }
        }

        vector<vector<string>> returnVector = {};

        for (const auto i: countList) {
            returnVector.push_back(i.second);
        }

        return returnVector;
    }
};
