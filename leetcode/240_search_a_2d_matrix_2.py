# Time: O(H log W), 各行で二分探索
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        H = len(matrix)
        W = len(matrix[0])
        for h in range(H):
            low = 0
            high = W - 1
            while low <= high:
                mid = (low + high) // 2
                num = matrix[h][mid]
                if num == target:
                    return True
                if num < target:
                    low = mid + 1
                else:
                    high = mid - 1
        return False


# O(H + W), 右上（または左下）からジグザグに歩く。
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        H = len(matrix)
        W = len(matrix[0])
        row, col = 0, W - 1 # right-top
        while row < H and 0 <= col:
            num = matrix[row][col]
            if num == target:
                return True
            if num < target:
                row += 1
            else:
                col -= 1
        return False