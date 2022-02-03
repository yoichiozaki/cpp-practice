# Time: O(N), 2Sumをちょっとひねった問題．相方がいるかを探すことで二重ループを回避する．
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        memo = [0 for _ in range(60)]
        ans = 0
        for t in time:
            ans += memo[(60 - t % 60) % 60]
            memo[t % 60] += 1
        return ans
