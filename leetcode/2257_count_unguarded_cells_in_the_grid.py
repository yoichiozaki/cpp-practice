class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        field = [[0 for _ in range(n)] for _ in range(m)]
        for (h, w) in guards + walls:
            field[h][w] = 1
        directions = [(0, 1), (1, 0), (-1, 0), (0, -1)]
        for (h, w) in guards:
            for (dh, dw) in directions:
                currh = h
                currw = w
                while 0 <= currh + dh < m and 0 <= currw + dw < n and field[currh + dh][currw + dw] != 1:
                    currh += dh
                    currw += dw
                    field[currh][currw] = 2
        return sum(1 for i in range(m) for j in range(n) if field[i][j] == 0) 