class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # dp[i]: whether s[:i] can be build from words in wordDict
        words = set(wordDict)  # for lookup in O(1)
        max_len = max(map(len, wordDict))
        dp = [True]
        for i in range(1, len(s)+1):
            dp += [any(dp[j] and s[j:i]
                       in words for j in range(max(0, i - max_len), i))]
        return dp[len(s)]
