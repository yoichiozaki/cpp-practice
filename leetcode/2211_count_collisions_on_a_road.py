class Solution:
    def countCollisions(self, directions: str) -> int:
        left = 0
        right = len(directions) - 1
        while left < len(directions) and directions[left] == "L":
            left += 1
        while 0 <= right and directions[right] == "R":
            right -= 1
        ans = 0
        for i in range(left, right + 1):
            if directions[i] != "S":
                ans += 1
        return ans
        
