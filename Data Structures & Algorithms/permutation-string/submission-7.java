class Solution {
    public boolean checkInclusion(String s1, String s2) {
        HashMap<Character, Integer> frequencyCount = new HashMap<>();

        HashMap<Character, Integer> s1CharCnt = new HashMap<>();

        for (char c: s1.toCharArray()) {
            s1CharCnt.put(c, s1CharCnt.getOrDefault(c, 0) + 1);
        }

        int l = 0;

        for (int r = 0; r < s2.length(); ++r) {
            char rightChar = s2.charAt(r);
            frequencyCount.put(rightChar, frequencyCount.getOrDefault(rightChar, 0) + 1);

            while (frequencyCount.get(rightChar) > s1CharCnt.getOrDefault(rightChar, 0)) {
                char leftChar = s2.charAt(l++);

                frequencyCount.put(leftChar, frequencyCount.get(leftChar) - 1);
            }

            if (r - l + 1 == s1.length()) {
                return true;
            }
        }

        return false;
    }
}
