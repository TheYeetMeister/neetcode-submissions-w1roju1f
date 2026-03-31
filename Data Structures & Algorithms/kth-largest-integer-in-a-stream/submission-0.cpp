class KthLargest {
    priority_queue<int> value;
    int k = k;
public:
    KthLargest(int k, vector<int>& nums): k(k - 1) {
        for (int i: nums) {
            value.push(i);
        }
    }
    
    int add(int val) {
        value.push(val);

        if (!k) {
            return value.top();
        }

        vector<int> storeThese{};
        storeThese.reserve(k);

        for (int i = 0; i < k; ++i) {
            storeThese.push_back(value.top());
            value.pop();
        }

        int returnThis = value.top();

        for (int i: storeThese) {
            value.push(i);
        }

        return returnThis;
    }
};
