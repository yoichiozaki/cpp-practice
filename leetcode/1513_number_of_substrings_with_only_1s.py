class Solution:
    def numSub(self, s: str) -> int:
        left = 0
        ans = 0
        for right in range(len(s)):
            if s[right] == "0":
                left = right + 1
                continue
            if s[left] == "0":
                left = right + 1
            ans += (right - left + 1)
        return ans % (10 ** 9 + 7)