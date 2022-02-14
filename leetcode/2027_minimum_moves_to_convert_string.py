# greedy
class Solution:
    def minimumMoves(self, s: str) -> int:
        i = 0
        N = len(s)
        cnt = 0
        while i < N:
            if s[i] == "X":
                cnt += 1
                i += 3
            else:
                i += 1
        return cnt
