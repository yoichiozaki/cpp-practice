class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        s = set() 
        accum = {0}
        for num in arr:
            accum = {num | a for a in accum} | {num}
            s = s | accum
        return len(s)