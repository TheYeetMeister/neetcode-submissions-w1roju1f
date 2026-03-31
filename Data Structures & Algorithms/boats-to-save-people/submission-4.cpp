class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        int boatCount = 0;

        while (l <= r) {
            int remain = limit - people[r--];
            ++boatCount;

            if (l <= r && remain >= people[l]) {
                ++l;
            }
        }

        return boatCount;
    }
};