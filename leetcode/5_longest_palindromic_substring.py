class Solution:
    def longestPalindrome(self, s: str) -> str:
        if s == "":
            return s
        ans = ""
        dp = [[None for _ in range(len(s))] for _ in range(len(s))]
        for j in range(len(s)):
            for i in range(j + 1):
                if i == j:
                    dp[i][j] = True
                elif i + 1 == j:
                    dp[i][j] = (s[i] == s[j])
                else:
                    dp[i][j] = (dp[i+1][j-1] and s[i] == s[j])
                    
                if dp[i][j] and len(ans) < j - i + 1:
                    ans = s[i:j + 1]
        return ans

    
    class Solution:
        def longestPalindrome(self, s: str) -> str:
            def expand_around_center(s, L, R):
                while 0 <= L and R < len(s) and s[L] == s[R]:
                    L -= 1
                    R += 1
                return R - L - 1
            
            if s == "":
                return ""
            start = 0
            end = 0
            for i in range(len(s)):
                l1 = expand_around_center(s, i, i)
                l2 = expand_around_center(s, i, i + 1)
                l = max(l1, l2)
                if end - start < l:
                    start = i - (l - 1) // 2
                    end = i + l // 2
            return s[start:end + 1]