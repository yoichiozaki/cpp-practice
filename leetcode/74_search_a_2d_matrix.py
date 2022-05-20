class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        H = len(matrix)
        W = len(matrix[0])
        low = 0
        high = H * W - 1
        while low <= high:
            mid = (low + high) // 2
            num = matrix[mid // W][mid % W]
            if num == target:
                return True
            elif num < target:
                low = mid + 1
            else:
                high = mid - 1
        return False