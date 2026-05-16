import string 
class Solution:
    letToNum = {
        char: index for index, char in enumerate(string.ascii_uppercase)
    }
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""
        
        n = len(str1)
        m = len(str2)

        val = math.gcd(n, m)
        return str1[:val]