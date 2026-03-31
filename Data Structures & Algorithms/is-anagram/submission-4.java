class Solution {
    private final int LETTERS_IN_ALPHA = 26;
    private int[] countFrequency(String word) {
        int[] charFrequency = new int[LETTERS_IN_ALPHA];

        for (char c: word.toCharArray()) {
            ++charFrequency[c - 'a'];
        }
        return charFrequency;
    }

    public boolean isAnagram(String s, String t) {
        int[] charSFrequency = countFrequency(s);
        int[] charTFrequency = countFrequency(t);

        for (int i = 0; i < LETTERS_IN_ALPHA; ++i) {
            if (charSFrequency[i] != charTFrequency[i]) {
                return false;
            }
        }

        return true;
    }
}
