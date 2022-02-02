# blute-force
# O(n^2)
class Solution:
    def maxArea(self, height: List[int]) -> int:
        ans = 0
        for left in range(len(height)):
            for right in range(len(height)):
                ans = max(ans, (right - left) *
                          min(height[left], height[right]))
        return ans


# いわゆるtwo-pointer
# O(n)
# (height[0], height[-1])がすべての長方形の中で最も横長で面積最大の候補の一つ
# それ以外の長方形は絶対に(height[0], height[-1])より幅が短いので，(height[0], height[-1])より高さがなければ絶対答えにならない
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        ans = 0
        while left < right:
            ans = max(ans, (right - left) * min(height[left], height[right]))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return ans
