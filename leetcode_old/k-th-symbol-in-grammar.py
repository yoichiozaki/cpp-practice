class Solution:
    def kthGrammar(self, N: int, K: int) -> int:
        if N == 1:
            return 0
        half = 1 << (N - 2)
        if K <= half:
            return self.kthGrammar(N - 1, K)
        else:
            return self.kthGrammar(N - 1, K - half) ^ 1
