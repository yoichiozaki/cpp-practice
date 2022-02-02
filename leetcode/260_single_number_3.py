# Time: O(n)
# Space: O(n)
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        s = set()
        for num in nums:
            if num in s:
                s.remove(num)
                continue
            s.add(num)
        return list(s)


# Time: O(n)
# Space: O(1)
# numsを全部xorした結果は2つの数字が混じってるのでこれを分解したい
# 立ってる桁に注目すると，その桁の1は必ず答えのどちらかに含まれる1なのでそれを利用する
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor1, xor2, i = 0, 0, 0
        # 全部のxorを取る
        for num in nums:
            xor1 ^= num

        # 1が立ってる最下位桁を取る
        for d in range(32):
            if xor1 & 1 << d:
                i = d
                break

        for num in nums:
            if num & 1 << i:
                xor2 ^= num

        return [xor1 ^ xor2, xor2]
