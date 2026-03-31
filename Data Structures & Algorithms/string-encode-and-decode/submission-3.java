class Solution {
    char delimiter = '@';

    public String encode(List<String> strs) {
        String outputString = "";

        for (String s: strs) {
            outputString += Integer.toString(s.length()) + delimiter + s;
        }

        System.out.println(outputString);
        return outputString;
    }

    public List<String> decode(String str) {
        List<String> res = new ArrayList<String>();
        String strNum = "";

        for (int i = 0; i < str.length(); ++i) {
            if (str.charAt(i) == delimiter) {
                int num = Integer.parseInt(strNum);
                int beginning = i + 1;
                int end = beginning + num;

                System.out.println(beginning + ": " + end);
                res.add(str.substring(beginning, end));

                strNum = "";
                i = end - 1;
            } else {
                strNum += str.charAt(i);
            }
        }

        return res;
    }
}
