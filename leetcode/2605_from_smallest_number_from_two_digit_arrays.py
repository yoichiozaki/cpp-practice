class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        ans = 100
        for digit1 in nums1:
            for digit2 in nums2:
                if digit1 == digit2:
                    ans = min(ans, digit1)
                else:
                    ans = min(ans, 10 * min(digit1, digit2) + max(digit1, digit2))
        return ans