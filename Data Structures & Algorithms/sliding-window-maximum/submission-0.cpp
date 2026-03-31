class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> numsQueue;

        vector<int> returnVector(nums.size() - k + 1);

        for (int i = 0; i < k - 1; ++i) {
            numsQueue.push(make_pair(nums[i], i));
        }

        for (int i = 0; i < nums.size() - k + 1; ++i) {
            numsQueue.push(make_pair(nums[i + k - 1], i + k - 1));

            while(true) {
                if (numsQueue.top().second >= i) {
                            returnVector[i] = numsQueue.top().first;
                            break;
                }       
                numsQueue.pop();
            }
        }

        return returnVector;
    }
};
