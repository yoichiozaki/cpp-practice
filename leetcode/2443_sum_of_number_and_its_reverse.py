class Solution:
    def sumOfNumberAndReverse(self, num: int) -> bool:
        def reverse(num):
            reversed_num = 0
            while num != 0:
                reversed_num = reversed_num * 10 + num % 10
                num = num // 10
            return reversed_num
        for i in range(num // 2, num + 1, 1):
            if i + reverse(i) == num:
                return True
        return False