class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        N = len(piles)
        
        @lru_cache(None)
        def dp(i, j): # pile[i:j+1]でゲームを開始した時の先手の最終得点
            if i > j: # 山札がない
                return 0
            if (j - i - N) % 2 == 1:
                return max(piles[i] + dp(i + 1, j), piles[j] + dp(i, j - 1))
            else:
                return min(-piles[i] + dp(i + 1, j), -piles[j] + dp(i, j - 1))
        return 0 < dp(0, N - 1)
            

# 実はゲーム自体は先手必勝。sum(piles)が必ず奇数になるので、最善の戦略を両者がとる場合、先手が必ず過半数を取る。厳密には帰納法。