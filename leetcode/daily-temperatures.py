class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ans = [0 for _ in range(len(temperatures))]
        stack = []
        for i in range(len(temperatures)-1, -1, -1):
            while len(stack) != 0 and stack[-1][0] <= temperatures[i]:
                stack.pop()
            if len(stack) != 0:
                ans[i] = stack[-1][1] - i
            stack.append((temperatures[i], i))
        return ans
