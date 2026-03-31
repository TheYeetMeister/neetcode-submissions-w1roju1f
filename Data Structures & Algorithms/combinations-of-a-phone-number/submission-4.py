class Solution:
    combos: dict = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz",
    }

    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        
        res = []

        def dfs(i: int, prevStr: str):
            if i == len(digits):
                res.append(prevStr)
                return

            for char in self.combos[digits[i]]:
                dfs(i + 1, prevStr + char)

        dfs(0, "")

        return res

        