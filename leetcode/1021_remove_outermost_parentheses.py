# スタックを使って切れ目を探し、切れ目がわかれば両端を除く。
class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        stack = []
        last = 0
        ans = ""
        for pos, ch in enumerate(s):
            if ch == "(":
                stack.append("(")
            else:
                if stack[-1] == "(":
                    stack.pop()
                    if len(stack) == 0:
                        ans += s[last + 1:pos]
                        last = pos + 1
        return ans