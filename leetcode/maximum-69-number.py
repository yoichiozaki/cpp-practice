class Solution:
    def maximum69Number(self, num: int) -> int:
        for i in range(3, -1, -1):
            if num // (10 ** i) % 10 == 6:
                num += 3 * 10 ** i
                break
        return num


class Solution:
    def maximum69Number(self, num: int) -> int:
        return int(str(num).replace('6', '9', 1))
