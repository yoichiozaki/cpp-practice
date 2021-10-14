# 部分文字列ごとに足し上げるとO(n^2)でTLE
# 文字ごとにその文字が1回のみ登場する部分列を数えて足し上げる
# Time: O(n)
class Solution:
    def uniqueLetterString(self, s: str) -> int:
        index = {c: [-1, -1] for c in string.ascii_uppercase}
        res = 0
        for i, c in enumerate(s):
            k, j = index[c]
            res += (i - j) * (j - k)
            index[c] = [j, i]
        for c in index:
            k, j = index[c]
            res += (len(s) - j) * (j - k)
        return res
