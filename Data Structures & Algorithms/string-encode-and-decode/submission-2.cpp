class Solution {
public:
    char delimiter = '@';

    string encode(vector<string>& strs) {
        string encodedString = "";

        for (string s: strs) {
            encodedString += to_string(s.size()) + delimiter + s;
        }

        return encodedString;

        //old original code
        /*
        string conglomeratedString = "";
        string indexString = "";
        for (string s: strs) {
            conglomeratedString.append(s);

            //creates index for where strings exist in the string
            indexString.append(to_string(s.size()));
            indexString.push_back(',');
        }

        return indexString + delimiter + conglomeratedString;
        */
    }

    vector<string> decode(string s) {
        vector<string> decodedWords {};

        unsigned index = 0;
        unsigned stringSize = 0;
        unsigned i = 0;

        string strSize;

        for (unsigned j = 0; j < s.size(); ++j) {
            if (s[j] == delimiter) {
                stringSize = stoi(s.substr(i, j));

                ++j;
                decodedWords.push_back(s.substr(j, stringSize));
                i = j + stringSize;
                j = i;
            }
        }

        return decodedWords;

        //old code
        /*
        vector<string> returnVector{};

        if (s.size() <= 1) {
            return returnVector;
        }

        size_t pos = s.find("@");
        
        string wordString = s.substr(pos + 1);
        string indexString = s.substr(0, pos);

        unsigned index = 0;
        unsigned size = 0;

        string numberString = "";

        for (char c: indexString) {
            if (c == ',') {
                index += size;
                size = stoi(numberString);
                numberString = "";

                returnVector.push_back(wordString.substr(index, size));
            } else {
                numberString.push_back(c);
            }
        }

        return returnVector;
        */
    }
};
