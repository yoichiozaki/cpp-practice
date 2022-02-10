class Solution:
    def minimumSum(self, num: int) -> int:
        num = sorted(str(num), reverse=True)
        n = len(num)
        res = 0
        position = 0
        for i in range(n):
            res += int(num[i]) * (10 ** position)
            if i % 2 == 1:
                position += 1
        return res
