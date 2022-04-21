class Solution:
    def numDecodings(self, s: str) -> int:
        # s[pos:]をdecodeしたときの場合の数
        N = len(s)
        def rec(pos):
            if pos == N:
                return 1
            if s[pos] == "0":
                return 0
            ans = rec(pos + 1)
            if pos + 1 < N and (s[pos] == "1" or (s[pos] == "2" and s[pos+1] < "7")):
                ans += rec(pos + 2)
            return ans
        return rec(0)

    
    class Solution:
        def numDecodings(self, s: str) -> int:
            N = len(s)
            memo = [-1 for _ in range(N + 1)]
            def rec(pos):
                if memo[pos] != -1:
                    return memo[pos]
                if pos == N:
                    return 1
                if s[pos] == "0":
                    return 0
                ans = rec(pos + 1)
                if pos + 1 < N and (s[pos] == "1" or (s[pos] == "2" and s[pos+1] < "7")):
                    ans += rec(pos + 2)
                memo[pos] = ans
                return ans
            return rec(0)

    
    class Solution:
        def numDecodings(self, s: str) -> int:
            p1 = 1
            p2 = 0
            for pos in range(len(s) - 1, -1, -1):
                curr = 0 if s[pos] == "0" else p1
                if pos < len(s) - 1 and (s[pos] == "1" or (s[pos] == "2" and s[pos + 1] <= "6")):
                    curr += p2
                p2 = p1
                p1 = curr
            return p1