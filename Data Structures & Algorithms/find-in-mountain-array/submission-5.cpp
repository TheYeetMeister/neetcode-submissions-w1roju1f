/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int MT_LENGTH;
    int findPeak(MountainArray &mountainArr) {
        int l = 0, r = MT_LENGTH - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;

            int midVal = mountainArr.get(mid);
            int lessMid = mountainArr.get(mid - 1);
            int moreMid = mountainArr.get(mid + 1);

            if (lessMid > midVal) {
                r = mid - 1;
            } else if (moreMid > midVal) {
                l = mid + 1;
            } else {
                return mid;
            }
        }

        return l;
    }

    int findTargetAsc(int target, int peakIndex, MountainArray &mountainArr) {
        int l = 0, r = peakIndex;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int midVal = mountainArr.get(mid);

            if (midVal > target) {
                r = mid - 1;
            } else if (midVal < target) {
                l = mid + 1;
            } else {
                return mid;
            }
        }

        return INT_MAX;
    }

    int findTargetDesc(int target, int peakIndex, MountainArray &mountainArr) {
        int l = peakIndex, r = MT_LENGTH - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int midVal = mountainArr.get(mid);

            if (midVal < target) {
                r = mid - 1;
            } else if (midVal > target) {
                l = mid + 1;
            } else {
                return mid;
            }
        }

        return INT_MAX;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        MT_LENGTH = mountainArr.length();
        
        int peakIndex = findPeak(mountainArr);

        int ans = findTargetAsc(target, peakIndex, mountainArr);

        if (ans != INT_MAX) {
            return ans;
        }

        ans = findTargetDesc(target, peakIndex, mountainArr);

        return (ans == INT_MAX)? -1: ans;
    }
};