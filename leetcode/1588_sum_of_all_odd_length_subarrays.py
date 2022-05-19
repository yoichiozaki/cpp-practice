class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        length = 1
        ans = 0
        while length <= len(arr):
            for i in range(len(arr) - length + 1):
                ans += sum(arr[i:i + length])
            length += 2
        return ans