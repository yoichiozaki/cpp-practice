# 尺取り法
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        left = 0
        ans = 0
        kind = Counter()
        for right in range(len(fruits)):
            kind[fruits[right]] += 1
            while 2 < len(kind):
                kind[fruits[left]] -= 1
                if kind[fruits[left]] == 0:
                    kind.pop(fruits[left])
                left += 1
            ans = max(ans, right - left + 1)
        return ans