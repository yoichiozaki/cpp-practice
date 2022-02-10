class Solution:
    def addDigits(self, num: int) -> int:
        while num < 0 or 10 <= num:
            total = 0
            while 0 < num:
                num, digit = divmod(num, 10)
                total += digit
            num = total
        return num
