class Solution:
    def countSubstrings(self, s: str) -> int:
        cnt = 0
        n = len(s)
        for i in range(n):
            for j in range(2):
                left = i
                right = left + j
                while 0 <= left and right < n and s[left] == s[right]:
                    cnt += 1
                    left -= 1
                    right += 1
        return cnt