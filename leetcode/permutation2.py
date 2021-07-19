class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ret = []

        def rec(cnt, sofar):
            if len(sofar) == len(nums):
                ret.append(sofar)
                return
            for num in cnt:
                if 0 < cnt[num]:
                    cnt[num] -= 1
                    rec(cnt, sofar + [num])
                    cnt[num] += 1
        cnt = Counter(nums)
        rec(cnt, [])
        return ret
