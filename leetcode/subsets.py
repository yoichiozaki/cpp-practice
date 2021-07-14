# 再帰関数
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        for i in range(1 << len(nums)):
            sub = []
            for j in range(len(nums)):
                if i & 1 << j:
                    sub.append(nums[j])
            ans.append(sub)
        return ans


# bit全探索
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ret = []
        for i in range(1 << len(nums)):
            lst = []
            for idx in range(len(nums)):
                if (1 << idx) & i:
                    lst.append(nums[idx])
            ret.append(lst)
        return ret
