class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int[] frequencyCount = new int[26];

        int[] s1CharCnt = new int[26];

        for (char c: s1.toCharArray()) {
            ++s1CharCnt[c - 'a'];
        }

        int l = 0;

        for (int r = 0; r < s2.length(); ++r) {
            char rightChar = s2.charAt(r);
            ++frequencyCount[rightChar - 'a'];

            while (frequencyCount[rightChar - 'a'] > s1CharCnt[rightChar - 'a']) {
                char leftChar = s2.charAt(l++);

                --frequencyCount[leftChar - 'a'];
            }

            if (r - l + 1 == s1.length()) {
                return true;
            }
        }

        return false;
    }
}
