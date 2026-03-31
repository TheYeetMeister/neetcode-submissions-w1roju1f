class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = ""

        def isPalindromic(i, j):
            while i < j:
                if s[i] != s[j]:
                    return False
                
                i += 1
                j -= 1
            
            return True

        for i in range(len(s)):
            for j in range(i, len(s)):
                if j - i + 1 > len(ans) and isPalindromic(i, j):
                    ans = s[i: j + 1]

        return ans
