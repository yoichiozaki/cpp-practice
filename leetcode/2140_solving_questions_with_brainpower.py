# 問題番号的に後ろのほうの問題から部分問題を作って考えるとDPになる
class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        N = len(questions)
        dp = [0 for _ in range(N)]
        dp[N - 1] = questions[N - 1][0]
        for i in range(N - 2, -1, -1):
            point = questions[i][0]
            skip = questions[i][1]
            if i + skip + 1 <= N - 1:
                dp[i] = max(point + dp[i + skip + 1], dp[i + 1])
            else:
                dp[i] = max(point, dp[i + 1])
        return dp[0]