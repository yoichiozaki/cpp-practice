class Solution:
    def countDigitOne(self, n: int) -> int:
        if n <= 0:
            return 0
        q, x, ans = n, 1, 0
        while 0 < q:
            digit = q % 10
            q //= 10
            ans += q * x
            if digit == 1:
                ans += n % x + 1
            elif digit >= 2:
                ans += x
            x *= 10
        return ans


# 各桁ごとに縦方向に数えるイメージ
# ex: 456123
#     456123 - 456100 => 100 の位にある 1 は 23 + 1 個
#     455199 - 455100 => 100 の位にある 1 は 100 個
#     454199 - 454100 => 100 の位にある 1 は 100 個
#     ...
#     000199 - 000100 => 100 の位にある 1 は 100 個 (100 x 4561)