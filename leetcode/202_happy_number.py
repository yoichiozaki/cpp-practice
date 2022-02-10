class Solution:
    def isHappy(self, n: int) -> bool:
        def calc_next(n):
            total = 0
            while 0 < n:
                n, d = divmod(n, 10)
                total += d * d
            return total
        slower = n
        faster = n
        while calc_next(faster) != 1 and calc_next(calc_next(faster)) != 1:
            slower = calc_next(slower)
            faster = calc_next(calc_next(faster))
            if slower == faster:
                return False
        return True


class Solution:
    def isHappy(self, n: int) -> bool:
        def calc_next(n):
            total = 0
            while 0 < n:
                n, d = divmod(n, 10)
                total += d * d
            return total
        slower = n
        faster = calc_next(n)
        while slower != faster and faster != 1:
            slower = calc_next(slower)
            faster = calc_next(calc_next(faster))
        return faster == 1
