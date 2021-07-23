class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ret = []

        def dfs(s, sofar):
            if s == "":
                ret.append(sofar[:])
                return
            for i in range(1, len(s) + 1):
                if s[:i] == s[i-1::-1]:  # is s[0:i] palindrome?
                    sofar.append(s[:i])
                    dfs(s[i:], sofar)
                    sofar.pop()

        dfs(s, [])
        return ret
