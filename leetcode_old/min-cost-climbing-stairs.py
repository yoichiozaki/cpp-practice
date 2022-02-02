class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        # dp[k]: minimum cost at position k
        # k = 0, 1, 2, ...

        dp = [0 for _ in range(len(cost))]
        dp[0] = cost[0]
        dp[1] = cost[1]
        if len(cost) <= 2:
            return min(dp[0], dp[1])
        for i in range(2, len(cost)):
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i]
        return min(dp[-1], dp[-2])  # 飛び越える or ぴったし着く
