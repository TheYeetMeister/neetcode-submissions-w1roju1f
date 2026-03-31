class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res: list[list[str]]  = []
        onePali: list[str] = []

        def isPali(s: str) -> bool:
            index = int(len(s) / 2)
            end = len(s) - 1

            for i in range(index):
                if s[i] != s[end - i]:
                    return False

            return True

        def dfs(prev: str, i: int):
            if i == len(s) and prev:
                return

            if len(s) == i:
                res.append(onePali.copy())
                return

            prev += s[i]
            dfs(prev, i + 1)

            if isPali(prev):
                onePali.append(prev)
                dfs("", i + 1)
                onePali.pop()

        dfs("", 0)

        return res
            