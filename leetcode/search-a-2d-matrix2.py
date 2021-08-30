# 各列に対して二分探索
# Time: O(h log w) or O(min(h log w, w log h))
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        H = len(matrix)
        W = len(matrix[0])

        for h in range(H):
            low = 0
            high = W - 1
            while low <= high:
                mid = (low + high) // 2
                if matrix[h][mid] == target:
                    return True
                elif matrix[h][mid] < target:
                    low = mid + 1
                else:
                    high = mid - 1
        return False


# 右上から左下へ探索範囲を絞っていく
# Time: O(h + w) ... 最長で右上から左下まで移動
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        H = len(matrix)
        W = len(matrix[0])

        # 右上
        h = 0
        w = W - 1

        while h < H and 0 <= w:
            if matrix[h][w] == target:
                return True
            elif matrix[h][w] < target:
                h += 1
            else:
                w -= 1

        return False


# 二分探索
# Time: O(h * log (w / h)) (h < w)
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        H = len(matrix)
        W = len(matrix[0])

        def search_submatrix(top_row, left_col, bottom_row, right_col):
            if top_row > bottom_row or left_col > right_col:
                return False

            mid_row = (top_row + bottom_row) // 2
            left = left_col
            right = right_col
            while left <= right:
                mid_col = (left + right) // 2
                if matrix[mid_row][mid_col] == target:
                    return True
                elif matrix[mid_row][mid_col] < target:
                    left = mid_col + 1
                else:
                    right = mid_col - 1

            upper_right = search_submatrix(
                top_row, left, mid_row - 1, right_col)
            lower_left = search_submatrix(
                mid_row + 1, left_col, bottom_row, right)

            return upper_right or lower_left

        return search_submatrix(0, 0, H - 1, W - 1)
