# brute-force
# 全部分列（2^N通り）を試す
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        if s == "":
            return 0

        # s[left:right+1]のsubsequenceの内，最長の長さを返す
        def rec(left, right):
            if left == right:
                return 1
            if left > right:
                return 0

            if s[left] == s[right]:
                return 2 + rec(left + 1, right - 1)
            else:
                return max(rec(left, right - 1), rec(left + 1, right))

        return rec(0, len(s)-1)


# メモ化：O(N^2)
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        if s == "":
            return 0

        memo = [[None for _ in range(len(s))] for _ in range(len(s))]

        # s[left:right+1]のsubsequenceの内，最長の長さを返す
        def rec(left, right):
            if memo[left][right] is not None:
                return memo[left][right]
            if left == right:
                memo[left][right] = 1
                return 1
            if left > right:
                memo[left][right] = 0
                return 0

            if s[left] == s[right]:
                memo[left][right] = 2 + rec(left + 1, right - 1)
            else:
                memo[left][right] = max(
                    rec(left, right - 1), rec(left + 1, right))
            return memo[left][right]

        return rec(0, len(s)-1)


# dp
# 添字の回し方に注意
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        if s == "":
            return 0

        # dp[i][j]: s[i:j+1]からの部分列の最大長
        # if s[i] == s[j]: dp[i][j] = 2 + dp[i+1][j-1]
        # else:            dp[i][j] = max(dp[i][j-1], dp[i+1][j])
        dp = [[0 for _ in range(len(s))] for _ in range(len(s))]
        for i in range(len(s)):
            dp[i][i] = 1

        for i in range(len(s) - 1, -1, -1):
            for j in range(i+1, len(s), 1):
                if s[i] == s[j]:
                    dp[i][j] = 2 + dp[i+1][j-1]
                else:
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j])

        return dp[0][-1]
