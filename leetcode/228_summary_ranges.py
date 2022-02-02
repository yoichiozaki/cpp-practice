class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ranges = []
        r = []
        for num in nums:
            if num - 1 not in r:
                r = []
                ranges += r,
            r[1:] = num,
        return ["->".join(map(str, r)) for r in ranges]
