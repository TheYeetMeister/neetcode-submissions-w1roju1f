class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //better memory solution
        vector<int> productVector(nums.size());
        int prefix = 1;

        for (int i = 0; i < nums.size(); ++i) {
            productVector[i] = prefix;

            prefix *= nums[i];
        }

        int postfix = 1;

        for (int i = nums.size() - 1; i > 0; --i) {
            productVector[i] = postfix * productVector[i];
            postfix *= nums[i];
        }

        productVector[0] = postfix;
        return productVector;

        /*
        vector<int> backwardsVector(nums.size());
        vector<int> forwardsVector(nums.size());
        vector<int> productVector(nums.size());

        int currProduct = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            currProduct *= nums[i];

            backwardsVector[i] = currProduct;
        }

        currProduct = 1;
        for (int i = 0; i < nums.size(); ++i) {
            currProduct *= nums[i];

            forwardsVector[i] = currProduct;
        }

        productVector[0] = backwardsVector[1];
        productVector[nums.size() - 1] = forwardsVector[nums.size() - 2];

        for (int i = 1; i < nums.size() - 1; ++i) {
            productVector[i] = backwardsVector[i + 1] * forwardsVector[i - 1];
        }

        return productVector;
        */
    }
};
