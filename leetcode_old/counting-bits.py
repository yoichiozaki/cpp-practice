class Solution:
    def countBits(self, num: int) -> List[int]:
        table = [0 for _ in range(num + 1)]
        for i in range(1, num + 1, 1):
            table[i] = table[i >> 1] + (i & 1)
        return table


# class Solution:
#     def countBits(self, num: int) -> List[int]:
#         return [bin(i).count('1') for i in range(num + 1)]
