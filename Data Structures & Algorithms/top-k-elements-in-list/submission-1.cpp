#include <unordered_map>

class Solution {
public:
    void updateTopCount(vector<int>& topElem, vector<int>& topCounts, int index, int count) {
        unsigned updateIndex = topCounts.size();
        for (int i = updateIndex - 1; i >= 0 && count > topCounts[i]; --i) {
            updateIndex = i;
        }

        for (unsigned i = topCounts.size() - 1; i > updateIndex; --i) {
            topCounts[i] = topCounts[i - 1];
            topElem[i] = topElem[i - 1];
        }

        if (updateIndex < topCounts.size()) {
            topCounts[updateIndex] = count;
            topElem[updateIndex] = index;
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, unsigned> intCount;
        vector<int> topElem(k, 0);
        vector<int> topCounts(k, 0);
        
        for (int i: nums) {
            auto foundElem = intCount.find(i);

            if (foundElem == intCount.end()) {
                intCount[i] = 1;
            } else {
                ++(foundElem->second);
            }
        }

        for (auto i: intCount) {
            updateTopCount(topElem, topCounts, i.first, i.second);
        }

        return topElem;
    }
};
