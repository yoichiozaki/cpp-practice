class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        ans = -1
        for pos in right:
            ans = max(ans, n - pos)
        for pos in left:
            ans = max(ans, pos)
        return ans