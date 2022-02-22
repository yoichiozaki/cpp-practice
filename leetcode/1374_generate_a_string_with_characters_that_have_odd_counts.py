class Solution:
    def generateTheString(self, n: int) -> str:
        if n % 2 == 0:
            return "x" + "y" * (n-1)
        else:
            return "x" * n
