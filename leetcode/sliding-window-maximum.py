# Blute-force
# Time: O(nk)
# Space: O(1) not including `ans`
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans = []
        for i in range(0, len(nums) - k + 1):
            ans.append(max(nums[i:i+k]))
        return ans


# dequeでindexで
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans = []
        q = collections.deque()
        for i in range(len(nums)):

            # 窓の左端を落とす
            if 0 < len(q) and q[0] <= i - k:
                q.popleft()

            # 新しく入ってくる数字より小さい数字は答え候補にならないので削除
            while 0 < len(q) and nums[q[-1]] < nums[i]:
                q.pop()
            q += (i,)

            if k - 1 <= i:
                ans.append(nums[q[0]])
        return ans
