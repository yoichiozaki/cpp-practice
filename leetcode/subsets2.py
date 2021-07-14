# 再帰関数
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ret = []

        def rec(pos, sofar):
            if pos == len(nums):
                sofar = sorted(sofar)
                if tuple(sofar) not in ret:
                    ret.append(tuple(sofar))
                return
            rec(pos + 1, sofar)
            rec(pos + 1, sofar + [nums[pos]])
        rec(0, [])
        return [list(s) for s in ret]


# bit全探索
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ret = []
        for i in range(1 << len(nums)):
            s = []
            for idx in range(len(nums)):
                if (1 << idx) & i:
                    s.append(nums[idx])
            s.sort()
            if tuple(s) not in ret:
                ret.append(tuple(s))
        return [list(s) for s in ret]
