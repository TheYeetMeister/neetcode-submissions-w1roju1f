class Solution {
    static int charCount = 52;

    private int indexLetter(char c) {
        if (Character.isUpperCase(c)) {
            return c - 'A';
        }
        return c - 'a' + 26;
    }

    public String minWindow(String s, String t) {
        if (t.length() > s.length()) {
            return "";
        }

        int[] tCount = new int[charCount];
        int[] sCount = new int[charCount];

        for (int i = 0; i < t.length(); ++i) {
            ++tCount[indexLetter(t.charAt(i))];
            ++sCount[indexLetter(s.charAt(i))];
        }

        int matches = 0;

        for (int i = 0; i < charCount; ++i) {
            if (sCount[i] >= tCount[i]) {
                ++matches;
            }
        }

        int length = Integer.MAX_VALUE;
        int lAns = 0;
        int rAns = 0;

        int l = 0;
        int r = t.length();

        for (; r <= s.length(); ++r) {
            while (matches == charCount) {
                if (r - l < length) {
                    lAns = l;
                    rAns = r;
                    length = r - l;
                }

                int charIndex = indexLetter(s.charAt(l++));
                if (sCount[charIndex]-- == tCount[charIndex]) {
                    --matches;
                }
            }

            if (r < s.length()) {
                int charIndex = indexLetter(s.charAt(r));
                if (++sCount[charIndex] == tCount[charIndex]) {
                    ++matches;
                }
            }
        }

        return (length == Integer.MAX_VALUE) ? "": s.substring(lAns, rAns);
    }
}
