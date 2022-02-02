class Solution:
    def nthUglyNumber(self, n: int) -> int:
        # 大きいugly numberは小さいugly number同士の積
        uglies = [1]
        ptr2 = 0
        ptr3 = 0
        ptr5 = 0
        while 1 < n:
            ugly2 = 2 * uglies[ptr2]
            ugly3 = 3 * uglies[ptr3]
            ugly5 = 5 * uglies[ptr5]
            ugly = min(ugly2, ugly3, ugly5)
            if ugly == ugly2:
                ptr2 += 1
            if ugly == ugly3:
                ptr3 += 1
            if ugly == ugly5:
                ptr5 += 1
            uglies.append(ugly)
            n -= 1
        return uglies[-1]
