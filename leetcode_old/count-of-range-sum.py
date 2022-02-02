# Blute-force
# 考えられるすべての連続する部分配列について，その部分配列の要素の和が[lower, upper]に収まっているかを判定して数え上げる
# sum()でO(n)かかるので全体としてはO(n^3)
class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        cnt = 0
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                if lower <= sum(nums[i:j+1]) <= upper:
                    cnt += 1
        return cnt


# 連続する部分配列の要素の和は累積和を用意しておくことでO(1)
# 全体としてはO(n^2)
class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        accum = [0 for _ in range(len(nums) + 1)]
        for i in range(1, len(nums) + 1):
            accum[i] = accum[i - 1] + nums[i - 1]
        cnt = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums) + 1):
                if lower <= accum[j] - accum[i] <= upper:
                    cnt += 1
        return cnt


# ポイント：累積和の任意の二箇所同士の差を取れば連続した部分配列の和を計算したことになる
# 上の2つの解法では，連続する部分列を行儀よく小さい方から（＝左端の位置が小さいものから）調べ上げている
# 答えを求めるのに際して，和の小さい部分列からカウントしても構わない
# TODO: 実装を間違ってる
class Solution:
    def __init__(self):
        self.count = 0
        self.upper = 0
        self.lower = 0

    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        self.upper = upper
        self.lower = lower

        accum = [0 for _ in range(len(nums) + 1)]
        for i in range(1, len(nums) + 1):
            accum[i] = accum[i - 1] + nums[i - 1]
        temp = [0 for _ in range(len(nums) + 1)]

        self.mergeSort(accum, 0, len(nums) - 1, temp)
        return self.count

    def mergeSort(self, accum, start, end, temp):
        if start >= end:
            return
        mid = (start + end) // 2

        # 右半分について条件を満たす部分列の個数を数える
        self.mergeSort(accum, start, mid, temp)

        # 左半分について条件を満たす部分列の個数を数える
        self.mergeSort(accum, mid + 1, end, temp)

        # midを跨ぐ部分列で条件を満たすものを数える
        self.merge(accum, start, mid, end, temp)

    def merge(self, accum, start, mid, end, temp):
        right = mid + 1
        index = start

        low = mid + 1
        high = mid + 1

        # leftを固定して行けるところまでlow/highを右に動かす
        for left in range(start, mid + 1):
            while low <= end and accum[low] - accum[left] < self.lower:
                low += 1
            while high <= end and accum[high] - accum[left] <= self.upper:
                high += 1

            # accumにおける，左端left，右端low+1 ~ 左端left，右端highの部分列が条件を満たす
            self.count += (high - low)

            while right <= end and accum[right] < accum[left]:
                temp[index] = accum[right]
                index += 1
                right += 1
            temp[index] = accum[left]
            index += 1

        while right <= end:
            temp[index] = accum[right]
            index += 1
            right += 1

        for i in range(start, end + 1):
            accum[i] = temp[i]
