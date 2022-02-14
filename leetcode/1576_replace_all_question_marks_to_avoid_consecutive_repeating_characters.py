# 前後が連続しないようにするためには"a", "b", "c"の3文字あれば足りる
class Solution:
    def modifyString(self, s: str) -> str:
        ans = ""
        prv = "?"
        for i, ch in enumerate(s):
            nxt = s[i+1] if i+1 < len(s) else "?"
            prv = ch if ch != "?" else {
                "a", "b", "c"}.difference({prv, nxt}).pop()
            ans += prv
        return ans
