class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_len = 0
        left = 0
        seen = dict()  # {char: latest pos}
        for right, char in enumerate(s):
            if char in seen and left <= seen[char]:
                left = seen[char] + 1
            else:
                max_len = max(max_len, right - left + 1)
            seen[char] = right
        return max_len
