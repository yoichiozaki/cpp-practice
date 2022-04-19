class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        # day iまでの旅程をカバーするチケットの最安コスト
        dp = [float("inf") for i in range(0, 370)]
        dp[0] = 0
        last_day = max(days)
        days = set(days)
        for day in range(1, 370):
            if day == last_day + 1:
                return dp[last_day]
            if day in days:
                dp[day] = min(
                    dp[max(0, day - 1)] + costs[0],
                    dp[max(0, day - 7)] + costs[1],
                    dp[max(0, day - 30)] + costs[2]
                )
            else:
                dp[day] = dp[day - 1]