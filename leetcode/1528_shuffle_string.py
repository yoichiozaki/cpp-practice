class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        res = ["" for _ in range(len(s))]
        for index, char in enumerate(s):
            res[indices[index]] = char
        return "".join(res)