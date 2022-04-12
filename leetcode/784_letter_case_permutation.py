class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        ans = []
        N = len(s)
        def rec(pos, sofar):
            if pos == N:
                ans.append(sofar)
                return
            if "0" <= s[pos] <= "9":
                rec(pos + 1, sofar + s[pos])
            else:
                rec(pos + 1, sofar + s[pos].lower())
                rec(pos + 1, sofar + s[pos].upper())
        rec(0, "")
        return ans