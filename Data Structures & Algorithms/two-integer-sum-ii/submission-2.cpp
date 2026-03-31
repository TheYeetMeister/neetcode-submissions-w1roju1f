class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;

        int sum = numbers[i] + numbers[j];

        while (i < j) {
            if (sum > target) {
                sum -= numbers[j];
                j--;

                sum += numbers[j];
            } else if (sum < target) {
                sum -= numbers[i];
                ++i;

                sum += numbers[i];
            } else {
                return vector<int>{i + 1, j + 1};
            }
        }

        return vector<int>{-1, -1};
    }
};
