class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        filled = s + (fill * (k-1))
        return [filled[i:i+k] for i in range(0, len(s), k)]
