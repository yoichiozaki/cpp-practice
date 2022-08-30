# https://zakimal.github.io/ja/post/volume-of-histogram/

# Time: O(N), Space: O(N), N := len(height)
class Solution:
    def trap(self, height: List[int]) -> int:
        N = len(height)
        left_max = [0 for _ in range(N)]
        right_max = [0 for _ in range(N)]
        
        left_max[0] = height[0]
        for i in range(1, N):
            left_max[i] = max(left_max[i - 1], height[i])
        
        right_max[N - 1] = height[N - 1]
        for i in range(N - 2, -1, -1):
            right_max[i] = max(right_max[i + 1], height[i])
        
        ans = 0
        for i in range(0, N):
            ans += min(left_max[i], right_max[i]) - height[i]
        return ans


# left_max, right_max を全部計算しきる前に確定する部分を足していくことで空間計算量を O(1) にできる
# 左右で高さの違いが発生した時点で、低いほうの棒の直後 or 直前の領域が棒の高さ分の水を取れる
class Solution:
    def trap(self, height: List[int]) -> int:
        N = len(height)
        left = 0
        right = N - 1
        height_of_wall = 0
        volume = 0
        while left < right:
            if height[left] <= height[right]:
                height_of_bottom = height[left]
                left += 1
                volume += max(0, height_of_wall - height_of_bottom)
                height_of_wall = max(height_of_wall, height_of_bottom)
            else:
                height_of_bottom = height[right]
                right -= 1
                volume += max(0, height_of_wall - height_of_bottom)
                height_of_wall = max(height_of_wall, height_of_bottom)
        return volume