class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> anagrams = new HashMap<>();

        for (String i: strs) {
            char[] values = i.toCharArray();
            Arrays.sort(values);
            String sortedString = new String(values);

            if (!anagrams.containsKey(sortedString)) {
                anagrams.put(sortedString, new ArrayList<>());
            }
            anagrams.get(sortedString).add(i);
        }

        System.out.println(anagrams.keySet());
        System.out.println(anagrams.values());


        return new ArrayList<>(anagrams.values());
    }
}
