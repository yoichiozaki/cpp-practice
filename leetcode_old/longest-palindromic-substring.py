class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expandAroundCenter(s, left, right):
            L = left
            R = right
            while 0 <= L and R < len(s) and s[L] == s[R]:
                L -= 1
                R += 1
            return R - L - 1

        if s == "":
            return ""
        start = 0
        end = 0
        for i in range(len(s)):
            l1 = expandAroundCenter(s, i, i)
            l2 = expandAroundCenter(s, i, i + 1)
            l = max(l1, l2)
            if end - start < l:
                start = i - (l - 1) // 2
                end = i + l // 2
        return s[start:end + 1]