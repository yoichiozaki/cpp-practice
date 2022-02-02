class Solution:
    def nextGreaterElement(self, n: int) -> int:
        digits = list(str(n))
        i = len(digits) - 1

        # 降順になっている部分を探す
        while 0 <= i - 1 and digits[i-1] >= digits[i]:
            i -= 1

        if i == 0:  # 全部降順 -> 次に大きい値は存在しない
            return -1

        j = i
        while j < len(digits) - 1 and digits[i-1] < digits[j+1]:
            j += 1

        digits[i-1], digits[j] = digits[j], digits[i-1]
        digits[i:] = digits[i:][::-1]
        ret = int("".join(digits))

        return ret if ret < 1 << 31 else -1
