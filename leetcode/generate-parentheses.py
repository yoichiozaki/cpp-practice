class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ret = []

        def rec(left, right, sofar):
            if left == n and right == n:
                ret.append(sofar)
                return
            if left < n:
                rec(left + 1, right, sofar + "(")
            if right < left:
                rec(left, right + 1, sofar + ")")
        rec(0, 0, "")
        return ret
