class Solution:
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        ans = 0
        pos = 0
        while pos < len(s):
            zero = 0
            one = 0
            while pos < len(s) and s[pos] == '0':
                zero += 1
                pos += 1
            while pos < len(s) and s[pos] == '1':
                one += 1
                pos += 1
            ans = max(ans, 2 * min(zero, one))
        return ans