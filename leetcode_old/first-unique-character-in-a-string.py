class Solution:
    def firstUniqChar(self, s: str) -> int:
        for idx, char in enumerate(s):
            if char in s[:idx] + s[idx+1:]:
                continue
            else:
                return idx
        return -1
