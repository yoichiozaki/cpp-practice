class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        subsum = 0
        table = dict()  # subsum: freq
        table[0] = 1
        for num in nums:
            subsum += num
            if subsum - k in table:
                ans += table[subsum - k]
            table[subsum] = table.get(subsum, 0) + 1
        return ans
