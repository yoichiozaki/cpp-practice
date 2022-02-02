class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        # カントールの対角線論法
        # 「nums[i]とはi桁目が違う」をi = 0, 1, 2, ...でやればいずれとも違う数字が出来上がる
        ans = ""
        for i, num in enumerate(nums):
            ans += str(1 - int(num[i]))
        return ans
