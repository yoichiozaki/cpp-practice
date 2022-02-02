# Maximum-size subarray with 2 kinds of elements
# 尺取法：左端を固定して右端を限界まで動かしていく．右端をこれ以上動かせなくなったところで，左端を動かす．
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        left = 0
        ans = 0
        s = Counter()
        for right in range(len(fruits)):
            s[fruits[right]] += 1
            while 2 < len(s):
                s[fruits[left]] -= 1
                if s[fruits[left]] == 0:
                    s.pop(fruits[left])
                left += 1
            ans = max(ans, right - left + 1)
        return ans
