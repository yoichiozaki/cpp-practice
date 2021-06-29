class NumArray:
    # Segment tree
    def __init__(self, nums: List[int]):
        n = len(nums)
        self.num = 1 << (n - 1).bit_length()
        self.tree = [0 for _ in range(2 * self.num)]
        for i in range(n):
            self.tree[self.num + i] = nums[i]
        for i in range(self.num - 1, 0, -1):
            self.tree[i] = self.tree[2 * i] + self.tree[2 * i + 1]

    def update(self, index: int, val: int) -> None:
        index += self.num
        self.tree[index] = val
        while 1 < index:
            self.tree[index >> 1] = self.tree[index] + self.tree[index ^ 1]
            index >>= 1

    def sumRange(self, left: int, right: int) -> int:
        right += 1
        ret = 0
        left += self.num
        right += self.num

        while left < right:
            if left & 1:
                ret += self.tree[left]
                left += 1
            if right & 1:
                ret += self.tree[right - 1]
            left >>= 1
            right >>= 1
        return ret


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)
