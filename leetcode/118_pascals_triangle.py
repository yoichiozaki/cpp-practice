class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        memo = dict()
        def rec(i):
            if i in memo:
                return memo[i]
            ret = [1]
            if i == 1:
                memo[i] = ret
                return ret
            subret = rec(i - 1)
            for j in range(len(subret) - 1):
                ret.append(subret[j] + subret[j + 1])
            ret.append(1)
            memo[i] = ret
            return ret
        return [rec(i) for i in range(1, numRows + 1)]