class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int threshold = nums.size() / 3;
        unordered_map<int, int> frequency;
        vector<int> res;

        for (int num: nums) {
            if (++frequency[num] == threshold + 1) {
                res.push_back(num);
            };
        }

        return res;
    }
};