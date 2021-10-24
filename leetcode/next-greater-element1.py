class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        next_greater = dict()
        for num in nums2:
            next_greater[num] = -1

        stack = []
        for i in range(len(nums2)-1, -1, -1):
            while len(stack) != 0 and stack[-1] <= nums2[i]:
                stack.pop()
            if len(stack) != 0:
                next_greater[nums2[i]] = stack[-1]
            stack.append(nums2[i])

        ans = [next_greater[num] for num in nums1]
        return ans
