class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        ans = []
        queens = {(q[0], q[1]) for q in queens}
        for dh in [-1, 0, 1]:
            for dw in [-1, 0, 1]:
                for times in range(1, 8):
                    h = king[0] + dh * times
                    w = king[1] + dw * times
                    if (h, w) in queens:
                        ans.append([h, w])
                        break
        return ans