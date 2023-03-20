class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        base = 1
        ans = 0
        for i in range(len(columnTitle) - 1, -1, -1):
            ans += (ord(columnTitle[i]) - ord('A') + 1) * base
            base *= 26
        return ans