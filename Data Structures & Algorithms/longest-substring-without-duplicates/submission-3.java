class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> charWindow = new HashSet<>();

        int i = 0, res = 0;

        for (int j = 0; j < s.length(); ++j) {
            char currChar = s.charAt(j);

            while (charWindow.contains(currChar)) {
                charWindow.remove(s.charAt(i));
                ++i;
            }

            if (j - i + 1> res) {
                res = j - i + 1;
            }
            charWindow.add(currChar);
        }

        return res;
    }
}
