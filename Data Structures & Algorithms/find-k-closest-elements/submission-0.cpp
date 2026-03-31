class Solution {
    bool isCloseToX(int a, int b, int x) {
        if (abs(a - x) == abs(b - x)) {
            return a < b;
        }
        return abs(a - x) < abs(b - x);
    }

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [this, x](int a, int b){return isCloseToX(a, b, x);});

        vector<int> res;
        res.reserve(k);

        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i]);
        }

        sort(res.begin(), res.end());

        return res;
    }
};