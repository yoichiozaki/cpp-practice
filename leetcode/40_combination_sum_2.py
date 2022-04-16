class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        def rec(candidates, pos, remain, sofar):
            if remain < 0:
                return
            if remain == 0:
                ans.append(sofar)
                return
            for i in range(pos, len(candidates)):
                if pos < i and candidates[i-1] == candidates[i]:
                    continue
                rec(candidates, i + 1, remain - candidates[i], sofar + [candidates[i]])
        candidates.sort()
        rec(candidates, 0, target, [])
        return ans
    