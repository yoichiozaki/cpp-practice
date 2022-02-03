class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        s = s1 + " " + s2
        freq = Counter(s.split())
        ans = []
        for k, v in freq.items():
            if v == 1:
                ans.append(k)
        return ans
