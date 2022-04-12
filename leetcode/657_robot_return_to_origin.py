class Solution:
    def judgeCircle(self, moves: str) -> bool:
        table = {
            "U": (0, +1),
            "D": (0, -1),
            "R": (+1, 0),
            "L": (-1, 0)
        }
        x = 0
        y = 0
        for op in moves:
            x += table[op][0]
            y += table[op][1]
        return (x, y) == (0, 0)


class Solution:
    def judgeCircle(self, moves: str) -> bool:
        return moves.count("U") == moves.count("D") and moves.count("R") == moves.count("L")