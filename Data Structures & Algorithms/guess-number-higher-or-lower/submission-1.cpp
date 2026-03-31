/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;

        while (l <= n) {
            int mid = l + ((n - l) / 2);

            int out = guess(mid);

            if (out < 0) {
                n = mid - 1;
            } else if (out > 0) {
                l = mid + 1;
            } else {
                return mid;
            }
        }

        return 0;
    }
};