class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        # length[i]: 右端がnums[i]である最長増加部分列の長さ
        # count[i] : 右端がnums[i]である最長増加部分列の個数
        # 求めるべきは sum(count[k])．ただし k は length の最大値のインデックス
        
        n = len(nums)
        length = [1 for _ in range(n)]
        count = [1 for _ in range(n)]
        for i in range(n):
            for j in range(0, i):
                if nums[j] < nums[i]:
                    if length[j] + 1 == length[i]:
                        count[i] += count[j]
                    if length[j] + 1 > length[i]:
                        length[i] = length[j] + 1
                        count[i] = count[j]
        max_length = max(length)
        return sum(count[i] for i in range(n) if length[i] == max_length)