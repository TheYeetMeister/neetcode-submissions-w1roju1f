class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> smallerVector = nums1, largerVector = nums2;

        if (smallerVector.size() > largerVector.size()) {
            swap(smallerVector, largerVector);
        }

        int total = nums1.size() + nums2.size();
        int half = (total + 1) / 2;

        int minLeft = 0;
        int minRight = smallerVector.size();

        while (minLeft <= minRight) {
            int i = (minLeft + minRight) / 2;
            int j = half - i;

            int aLeft = (i > 0) ? smallerVector[i - 1] : INT_MIN;
            int aRight = (i < smallerVector.size()) ? smallerVector[i] : INT_MAX;
            int bLeft = (j > 0) ? largerVector[j - 1] : INT_MIN;
            int bRight= (j < largerVector.size()) ? largerVector[j] : INT_MAX;

            if (aLeft <= bRight && bLeft <= aRight) {
                if (total % 2) {
                    return (max(aLeft, bLeft));
                } else {
                    return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
                }
            } else if (aLeft > bRight) {
                minRight = i - 1;
            } else {
                minLeft = i + 1;
            }
        }

        return -1;
    }
};
