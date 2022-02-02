# recursion
class Solution:
    def numDecodings(self, s: str) -> int:
        if s == "":
            return 0

        # s[pos:]の有効な変換を数える
        def rec(pos):
            if pos == len(s):
                return 1
            if s[pos] == "0":
                return 0
            ret = rec(pos + 1)
            if pos < len(s) - 1 and (s[pos] == "1" or (s[pos] == "2" and s[pos + 1] <= "6")):
                ret += rec(pos + 2)
            return ret

        return rec(0)


# メモ化
class Solution:
    def numDecodings(self, s: str) -> int:
        if s == "":
            return 0

        memo = [None for _ in range(len(s) + 1)]
        memo[len(s)] = 1

        # s[pos:]の有効な変換を数える
        def rec(pos):
            if memo[pos] is not None:
                return memo[pos]
            if s[pos] == "0":
                memo[pos] = 0
                return 0
            ret = rec(pos + 1)
            if pos < len(s) - 1 and (s[pos] == "1" or (s[pos] == "2" and s[pos+1] <= "6")):
                ret += rec(pos + 2)
            memo[pos] = ret
            return ret

        return rec(0)


# dp
class Solution:
    def numDecodings(self, s: str) -> int:
        if s == "":
            return 0

        # dp[i]: s[i:]の有効な変換数
        dp = [None for _ in range(len(s) + 1)]
        dp[len(s)] = 1
        for pos in range(len(s)-1, -1, -1):
            if s[pos] == "0":
                dp[pos] = 0
            else:
                dp[pos] = dp[pos + 1]
                if pos < len(s) - 1 and (s[pos] == "1" or (s[pos] == "2" and s[pos + 1] <= "6")):
                    dp[pos] += dp[pos + 2]
        return dp[0]


# constant dp
class Solution:
    def numDecodings(self, s: str) -> int:
        if s == "":
            return 0

        p1 = 1
        p2 = 0
        for pos in range(len(s) - 1, -1, -1):
            curr = 0 if s[pos] == "0" else p1
            if pos < len(s) - 1 and (s[pos] == "1" or (s[pos] == "2" and s[pos + 1] <= "6")):
                curr += p2
            p2 = p1
            p1 = curr
        return p1
