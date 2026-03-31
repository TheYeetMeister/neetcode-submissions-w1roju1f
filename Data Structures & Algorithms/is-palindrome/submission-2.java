class Solution {
    private boolean validLetter(char c) {
        return (c >= '0' && c <= '9' ||
                c >= 'a' && c <= 'z' ||
                c >= 'A' && c <= 'Z');
    }
    public boolean isPalindrome(String s) {
        int l = 0, r = s.length() - 1;

        while (l < r) {
            if (!validLetter(s.charAt(l))) {
                ++l;
                continue;
            }

            if (!validLetter(s.charAt(r))) {
                --r;
                continue;
            }
            char leftChar = s.charAt(l++);
            char rightChar = s.charAt(r--);

            if (Character.toLowerCase(leftChar) != Character.toLowerCase(rightChar)) {
                return false;
            }
        }

        return true;
    }
}
