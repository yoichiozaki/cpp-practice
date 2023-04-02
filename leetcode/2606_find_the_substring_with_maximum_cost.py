class Solution:
    def maximumCostSubstring(self, s: str, chars: str, vals: List[int]) -> int:
        char2val = dict()
        for i in range(len("abcdefghijklmnopqrstuvwxyz")):
            char2val["abcdefghijklmnopqrstuvwxyz"[i]] = i + 1
        for i in range(len(chars)):
            char = chars[i]
            val = vals[i]
            char2val[char] = val
        prevsum = 0
        ans = prevsum
        for i in range(0, len(s)):
            prevsum = max(prevsum + char2val[s[i]], char2val[s[i]])
            ans = max(ans, prevsum)
        return ans