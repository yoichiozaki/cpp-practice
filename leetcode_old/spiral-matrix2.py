class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[None for _ in range(n)] for _ in range(n)]

        def _coords_by_layer(r0, c0, r1, c1):
            for c in range(c0, c1 + 1, 1):
                yield r0, c
            for r in range(r0 + 1, r1 + 1, 1):
                yield r, c1
            if r0 < r1 and c0 < c1:
                for c in range(c1 - 1, c0, -1):
                    yield r1, c
                for r in range(r1, r0, -1):
                    yield r, c0

        r0 = 0
        c0 = 0
        r1 = n - 1
        c1 = n - 1
        num = 1
        while r0 <= r1:
            for r, c in _coords_by_layer(r0, c0, r1, c1):
                ans[r][c] = num
                num += 1
            r0 += 1
            r1 -= 1
            c0 += 1
            c1 -= 1
        return ans
