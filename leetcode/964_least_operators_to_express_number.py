class Solution:
    def leastOpsExpressTarget(self, x: int, target: int) -> int:
        memo = dict()
        def rec(x, target):
            if target in memo:
                return memo[target]
            
            if target < x:
                return min(
                    target * 2 - 1,  # adding x/x (= 1) up to target, ex) x/x + x/x + x/x
                    (x - target) * 2 # substract x/x down to target, ex) x - x/x - x/x
                )
            
            if target == x:
                return 0
            
            sigma = x
            times = 0
            while sigma < target:
                sigma *= x
                times += 1
            if sigma == target:
                memo[target] = times
                return memo[target]
            memo[target] = float("inf")
            if sigma - target < target:
                memo[target] = rec(x, sigma - target) + times + 1
            memo[target] = min(
                memo[target],
                rec(x, target - sigma // x) + times
            )
            return memo[target]
        return rec(x, target)
