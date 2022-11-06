class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        lst = [(-height, name) for (height, name) in zip(heights, names)]
        lst.sort()
        return [ele[1] for ele in lst]