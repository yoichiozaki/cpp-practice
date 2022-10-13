class Solution:
    def maxPower(self, s: str) -> int:
        left = 0
        ans = 0
        for right in range(len(s)):
            if s[left] != s[right]:
                left = right
            ans = max(ans, right - left + 1)
        return ans