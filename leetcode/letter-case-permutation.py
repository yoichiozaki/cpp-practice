class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        ret = []

        def rec(pos, sofar):
            if pos == len(S):
                ret.append(sofar)
                return
            if S[pos].isalpha():
                rec(pos + 1, sofar + S[pos])
                rec(pos + 1, sofar + S[pos].swapcase())
            else:
                rec(pos + 1, sofar + S[pos])
        rec(0, "")
        return ret
