class Solution:
    def countHomogenous(self, s: str) -> int:
        left = 0
        ans = 0
        for right in range(len(s)):
            if s[left] != s[right]:
                left = right
            ans = (ans % (10**9 + 7) + (right - left + 1) % (10**9 + 7)) % (10**9 + 7)
        return ans 