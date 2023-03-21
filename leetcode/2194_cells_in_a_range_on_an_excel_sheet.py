class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        lst = s.split(":")
        start = (ord(lst[0][0]) - ord('A'), int(lst[0][1]))
        end = (ord(lst[1][0]) - ord('A'), int(lst[1][1]))
        ans = []
        for i in range(start[0], end[0] + 1, 1):
            for j in range(start[1], end[1] + 1, 1):
                ans.append(str(chr(i + ord('A'))) + str(j))
        return ans
