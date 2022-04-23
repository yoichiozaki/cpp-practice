class Solution:
    def canJump(self, nums: List[int]) -> bool:
        reachable = 0
        for pos, num in enumerate(nums):
            if reachable < pos:
                return False
            reachable = max(reachable, pos + num)
        return True