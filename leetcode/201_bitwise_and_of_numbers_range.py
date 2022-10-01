# [left, right] の連続する数列なので、2進数表記した時に小さい桁の部分がペラペラ変わる
# 全部の数のbitwise-andを取るということは、異なる桁が何桁あるかがわかれば良くて、1の桁からx桁分で0/1が混ざるということがわかれば、答えは0/1が混ざらない桁以降にx個0を続けた数になる
class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        if left == 0:
            return 0
        i = 0
        while left != right:
            i += 1
            left = left >> 1
            right = right >> 1
        return left << i