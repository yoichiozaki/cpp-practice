class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        freq = dict()
        for s in arr:
            if s not in freq:
                freq[s] = 1
            else:
                freq[s] += 1
        for s in arr:  # ここで元の順番通りに参照する
            if freq[s] == 1:
                if k == 1:
                    return s
                else:
                    k -= 1
        return ""
