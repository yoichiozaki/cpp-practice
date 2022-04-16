# まず(を置いて、置きすぎたら)を置く
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def rec(left, right, sofar):
            if left == n and right == n:
                ans.append(sofar)
                return
            if left < n:
                rec(left + 1, right, sofar + "(")
            if left > right:
                rec(left, right + 1, sofar + ")")
        rec(0, 0, "")
        return ans
    