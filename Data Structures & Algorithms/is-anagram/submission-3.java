class Solution {
    public boolean isAnagram(String s, String t) {
        int[] charSFrequency = new int[26];

        for (char c: s.toCharArray()) {
            ++charSFrequency[c - 'a'];
        }

        int[] charTFrequency = new int[26];
        for (char c: t.toCharArray()) {
            ++charTFrequency[c - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (charSFrequency[i] != charTFrequency[i]) {
                return false;
            }
        }

        return true;
    }
}
