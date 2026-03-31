class Solution {
    static final int NUMBER_OF_CHARS = 26;
    static final String delimiter = ":";

    private int[] createFrequencyList(String word) {
        int[] frequencyList = new int[NUMBER_OF_CHARS];

        for (int i = 0; i < word.length(); ++i) {
            ++frequencyList[word.charAt(i) - 'a'];
        }

        return frequencyList;
    }

    private String frequencyListToString(int[] frequencyList) {
        return Arrays.stream(frequencyList)
                .mapToObj(String::valueOf)
                .collect(Collectors.joining(delimiter));
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> anagrams = new HashMap<>();

        for (String i: strs) {
            int[] frequencyList = createFrequencyList(i);
            String frequencyString = frequencyListToString(frequencyList);

            if (!anagrams.containsKey(frequencyString)) {
                anagrams.put(frequencyString, new ArrayList<>());
            }
            anagrams.get(frequencyString).add(i);
        }

        return new ArrayList<>(anagrams.values());
    }
}
