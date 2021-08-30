class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        h = len(matrix)
        w = len(matrix[0])

        low = 0
        high = h * w - 1

        while low <= high:
            mid = (low + high) // 2
            num = matrix[mid // w][mid % w]
            if num == target:
                return True
            elif num < target:
                low = mid + 1
            else:
                high = mid - 1
        return False
