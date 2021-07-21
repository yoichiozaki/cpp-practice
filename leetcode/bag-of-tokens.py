class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        left = 0
        right = len(tokens) - 1
        ans = 0
        score = 0
        while left <= right:
            if tokens[left] <= power:
                score += 1
                power -= tokens[left]
                left += 1
                ans = max(ans, score)
            elif power < tokens[left] and 0 < score:
                score -= 1
                power += tokens[right]
                right -= 1
            else:
                return ans
        return ans
