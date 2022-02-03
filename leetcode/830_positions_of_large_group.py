# Time: O(n)，いわゆる 2 Pointers テクニック
class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        ans = []
        if len(s) == 1:
            return ans
        left = 0
        for right in range(1, len(s)+1, 1):
            if right == len(s) or s[left] != s[right]:
                if right - left >= 3:
                    ans.append([left, right-1])
                left = right
        return ans


class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        left, right, N = 0, 0, len(s)
        ans = []
        while left < N:
            while right < N and s[left] == s[right]:
                right += 1
            if 3 <= right - left:
                ans.append([left, right-1])
            left = right
        return ans
