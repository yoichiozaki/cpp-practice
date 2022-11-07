# k以下の数でできるだけ桁数の多い2進数が欲しいので、できるだけ1は要らなくて0が欲しい
# というのを貪欲に下の桁からやると答えが求まる
# が、どういう発想でそうなるのかわからない。。。
class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        ans = 0
        base = 1
        N = len(s)
        for i in range(N - 1, -1, -1):
            if s[i] == "0" or base <= k:
                if s[i] == "1":
                    k -= base
                ans += 1
            if base <= k:
                base *= 2
        return ans