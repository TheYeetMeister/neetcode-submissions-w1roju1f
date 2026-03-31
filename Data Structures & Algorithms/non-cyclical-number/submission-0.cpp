class Solution {
    int calculateNewNum(int n) {
        int sum = 0;

        while (n) {
            int num = n % 10;
            sum += num * num;

            n /= 10;
        }

        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> cache;
        cache.insert(n);

        while (n != 1) {
            n = calculateNewNum(n);

            if (cache.find(n) != cache.end()) {
                return false;
            }

            cache.insert(n);
        }

        return true;
    }
};
