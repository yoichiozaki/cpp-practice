class Solution:
    def longestPalindrome(self, s: str) -> int:
        pairs = 0
        unpaired = set()
        for ch in s:
            if ch in unpaired:
                pairs += 1
                unpaired.remove(ch)
            else:
                unpaired.add(ch)
        if unpaired:
            return pairs * 2 + 1
        else:
            return pairs * 2