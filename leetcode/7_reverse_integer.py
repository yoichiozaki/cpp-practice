class Solution:
    def reverse(self, x: int) -> int:
        if x <= -2**31 or 2**31 - 1 <= x:
            return 0

        s = str(x)
        r = ""
        if 0 <= x:
            r = s[::-1]
        else:
            tmp = s[1:]
            r = "-" + tmp[::-1]
        if int(r) <= -2**31 or 2**31 - 1 <= int(r):
            return 0
        return int(r)
