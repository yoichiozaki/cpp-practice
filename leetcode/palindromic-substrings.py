# dp
# 回文の定義から，s[i:j]が回文 and s[i-1] == s[j+1] => s[i-1:j+1]も回文
class Solution:
    def countSubstrings(self, s: str) -> int:
        if s == "":
            return 0

        # dp[i][j] = s[i:j]が回文
        n = len(s)
        dp = [[False for _ in range(n)] for _ in range(n)]

        # 1文字からなる回文
        for i in range(n):
            dp[i][i] = True

        # 2文字からなる回文
        for i in range(n-1):
            if s[i] == s[i+1]:
                dp[i][i+1] = True

        # 3文字以上からなる回文
        for k in range(3, n+1):
            for i in range(n - (k - 1)):
                j = i + k - 1
                if dp[i+1][j-1] and s[i] == s[j]:
                    dp[i][j] = True

        ans = 0
        for i in range(n):
            for j in range(n):
                if dp[i][j]:
                    ans += 1
        return ans


# 回文の「中央」について全部調べ上げて数える解法
# 奇数長の回文：「中央」は1文字 | aaa_b_aaa
# 偶数長の回文：「中央」は2文字 | aaa_bb_aaa
# 長さNの文字列から，回分の「中央」になりえるのは2N-1箇所
# 例：N = 3 -> 「中央」候補は s[0:0], s[0:1], s[1:1], s[1:2], s[2:2]の5（ = 2*3 - 1）
class Solution:
    def countSubstrings(self, s: str) -> int:
        ans = 0
        n = len(s)
        for i in range(n):
            for j in range(2):
                left = i
                right = left + j

                while 0 <= left and right < n and s[left] == s[right]:
                    ans += 1
                    left -= 1
                    right += 1
        return ans
