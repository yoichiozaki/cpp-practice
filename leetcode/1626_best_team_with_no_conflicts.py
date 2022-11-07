# 得点力の大小が年齢の大小と矛盾しなければ不和が生まれない。年齢順に選手を並べたときに、得点力も非減少数列になる。
# ここまで言い換えられれば、非減少部分列の和の最大値を求めればい良いことになる。
# dp[i]: 右端がarr[i]である非減少部分列の和の最大値
class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        players = list(zip(ages, scores))
        N = len(players)
        players.sort()
        dp = [0 for _ in range(N)]
        ans = 0
        for i in range(N):
            dp[i] = players[i][1] # i 番目の人だけからなる非減少部分列も答えの候補
            for j in range(0, i, 1):
                if players[j][1] <= players[i][1]: # score_j <= score_i なので i 番目の人を非減少部分列に含めてもよいことになる
                    dp[i] = max(dp[i], dp[j] + players[i][1])
            ans = max(ans, dp[i]) # i 番目の人が右端となるパターンの全部を対象に最大値を取ることで全部調べつくすことになる
        return ans