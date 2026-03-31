// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
    vector<Pair> createListCopy(vector<Pair>& pairs) {
        vector<Pair> returnList;
        returnList.reserve(pairs.size());

        for (Pair elem: pairs) {
            returnList.push_back({elem.key, elem.value});
        }

        return returnList;
    }

    void sortOneElementBackwards(int currLargestIndex, vector<Pair>& pairs) {
        unsigned index = 0;

        for (; index < currLargestIndex && pairs[currLargestIndex].key >= pairs[index].key; ++index);

        Pair currPair = pairs[currLargestIndex];

        for(; index < currLargestIndex; ++index) {
            Pair temp = pairs[index];
            pairs[index] = currPair;
            currPair = temp;
        }

        pairs[index] = currPair;
    }
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> sortHistory;

        for (int i = 0; i < pairs.size(); ++i) {
            sortOneElementBackwards(i, pairs);
            sortHistory.push_back(createListCopy(pairs));
        }

        return sortHistory;
    }
};
