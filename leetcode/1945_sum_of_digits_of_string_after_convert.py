class Solution:
    def getLucky(self, s: str, k: int) -> int:
        t = ""
        for ch in s:
            t += str(ord(ch) - ord("a") + 1)
        n = int(t)
        for _ in range(k):
            total = 0
            while 0 < n:
                n, d = divmod(n, 10)
                total += d
            n = total
        return n
