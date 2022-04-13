class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        def rec(candidates, remain, sofar):
            if remain < 0:
                return
            if remain == 0:
                ans.append(sofar)
                return
            for i in range(len(candidates)):
                rec(candidates[i:], remain - candidates[i], sofar + [candidates[i]])
        rec(candidates, target, [])
        return ans