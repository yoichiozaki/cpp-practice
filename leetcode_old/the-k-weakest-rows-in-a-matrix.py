class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        soldiers = [(idx, sum(row)) for idx, row in enumerate(mat)]
        soldiers.sort(key=lambda x: x[1])
        return [idx for (idx, _) in soldiers[:k]]
