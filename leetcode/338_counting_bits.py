# 2x = (x << 1)であって，2xに含まれる1はxと同じ（2xは「x0」）．あとはxが奇数かどうかで調整
class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0 for _ in range(n+1)]
        for i in range(1, n+1, 1):
            ans[i] = ans[i >> 1]
            if i & 1 == 1:
                ans[i] += 1
        return ans

# 奇数かどうかで調整パターン
# (a + b) / 2 = a + (a - b) / 2 = a / 2 + b / 2 + (a AND b AND 1)
