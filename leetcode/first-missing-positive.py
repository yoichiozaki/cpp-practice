class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # l = len(nums) とすると，答え候補となるのは 1, 2, ..., l, l + 1
        # これらのうちから， nums に含まれていない整数を求めれば良い

        nums.append(0)  # mod (l + 1) で分類できるように配列を確保
        N = len(nums)

        for i in range(N):
            # 答え候補以外を削除
            if nums[i] < 0 or N < nums[i]:
                nums[i] = 0

            if nums[i] == N:
                nums[i] = 0

        for i in range(N):
            nums[nums[i] % N] += N

        for i in range(1, N):
            if nums[i] < N:
                return i
        return N
