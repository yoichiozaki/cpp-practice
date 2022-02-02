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


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        class MonoQueue:
            def __init__(self):
                self.que = collections.deque()

            def push(self, val):
                count = 0
                while len(self.que) != 0 and self.que[-1][0] < val:
                    count += self.que[-1][1] + 1
                    self.que.pop()
                self.que.append([val, count])

            def max(self):
                return self.que[0][0]

            def pop(self):
                if 0 < self.que[0][1]:
                    self.que[0][1] -= 1
                    return
                else:
                    self.que.popleft()

        ans = []
        mq = MonoQueue()
        k = min(k, len(nums))
        for i in range(0, k - 1):
            mq.push(nums[i])
        for i in range(k - 1, len(nums)):
            mq.push(nums[i])
            ans.append(mq.max())
            mq.pop()
        return ans
