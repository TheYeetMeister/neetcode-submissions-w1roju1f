class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> curr{0, 0, 0};
        for (vector<int> triplet: triplets) {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) {
                continue;
            }

            for (int i = 0; i < 3; ++i) {
                curr[i] = max(curr[i], triplet[i]);
            }
        }

        for (int i = 0; i < 3; ++i) {
            if (curr[i] != target[i]) {
                return false;
            }
        }

        return true;
    }
};
