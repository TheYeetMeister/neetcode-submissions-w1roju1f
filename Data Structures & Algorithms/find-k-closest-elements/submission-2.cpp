class Solution {
    bool comparator(int a, int b, int x) {
        if (abs(a - x) == abs(b - x)) {
            return a < b;
        }
        return abs(a - x) < abs(b - x);
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int r = k;
        
        for (; r < arr.size() 
            && (arr[r - 1] == arr[r] 
            || comparator(arr[r], arr[r - k], x)); ++r);

        int l = r - k;

        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};