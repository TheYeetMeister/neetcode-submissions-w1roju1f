class Solution {
    vector<int> prefixSum;
    int n;

    bool canSplit(int largest, int k) {
        int subarrays = 0, i = 0;
        while (i < n) {
            int l = i + 1, r = n;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (prefixSum[mid] - prefixSum[i] <= largest) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            ++subarrays;
            i = r;
            if (subarrays > k) {
                return false;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        n = nums.size();
        prefixSum.reserve(n + 1);
        prefixSum.push_back(0);
        for (int i = 0; i < n; ++i) {
            prefixSum.push_back(prefixSum[i] + nums[i]);
        }

        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int res = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canSplit(mid, k)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};