# Time: O(R * C), Space: O(R + C)
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        R = len(matrix)
        C = len(matrix[0])
        rows = set()
        cols = set()
        for r in range(R):
            for c in range(C):
                if matrix[r][c] == 0:
                    rows.add(r)
                    cols.add(c)

        for r in range(R):
            for c in range(C):
                if r in rows or c in cols:
                    matrix[r][c] = 0


# Time: O(R * C), Space: O(1)
# 0行目と0列目は特別扱いして最後に0埋めする
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        is_col0_zero = False
        R = len(matrix)
        C = len(matrix[0])

        for r in range(R):
            if matrix[r][0] == 0:
                is_col0_zero = True
            for c in range(1, C):
                if matrix[r][c] == 0:
                    matrix[0][c] = 0
                    matrix[r][0] = 0

        for r in range(1, R):
            for c in range(1, C):
                if matrix[r][0] == 0 or matrix[0][c] == 0:
                    matrix[r][c] = 0

        if matrix[0][0] == 0:
            for c in range(1, C):
                matrix[0][c] = 0
        if is_col0_zero:
            for r in range(R):
                matrix[r][0] = 0
