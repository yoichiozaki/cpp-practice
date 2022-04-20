class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        # dp[i]: pairs[i]で終わる鎖の長さの最大値
        dp = [1 for _ in range(len(pairs))]
        pairs.sort()
        for i in range(len(pairs)):
            for j in range(i):
                if j != i and pairs[j][1] < pairs[i][0]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)


class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        ans = 0
        rightmost = float("-inf")
        for left, right in sorted(pairs, key=operator.itemgetter(1)):
            if rightmost < left:
                rightmost = right
                ans += 1
        return ans