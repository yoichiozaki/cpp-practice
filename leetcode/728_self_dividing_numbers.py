class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        ans = []
        for i in range(left, right + 1):
            if all(ch != "0" and i % int(ch) == 0 for ch in str(i)):
                ans.append(i)
        return ans