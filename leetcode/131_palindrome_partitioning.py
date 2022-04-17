class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ans = []
        def rec(s, palindromes):
            if len(s) == 0:
                ans.append(palindromes[:])
                return
            for i in range(1, len(s) + 1):
                if s[:i] == s[i-1::-1]:
                    palindromes.append(s[:i])
                    rec(s[i:], palindromes)
                    palindromes.pop()
        rec(s, [])
        return ans