# 各iごとに左右を見るのではなくて，右だけ全部見て，その後に左全部見るというやり方
class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        ans = []

        prev = float("-inf")
        for i in range(0, len(s), 1):
            if s[i] == c:
                prev = i
            ans.append(i - prev)

        prev = float("inf")
        for i in range(len(s)-1, -1, -1):
            if s[i] == c:
                prev = i
            ans[i] = min(ans[i], prev - i)

        return ans
