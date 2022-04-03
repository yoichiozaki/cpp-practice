class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = []
        if matrix is None:
            return ans
        if len(matrix) == 0:
            return ans
        start_row = 0
        end_row = len(matrix) - 1
        start_col = 0
        end_col = len(matrix[0]) - 1
        direction = 0 # right
        while start_row <= end_row and start_col <= end_col:
            if direction == 0: # right
                for col in range(start_col, end_col + 1, +1):
                    ans.append(matrix[start_row][col])
                start_row += 1
            elif direction == 1: # down
                for row in range(start_row, end_row + 1, +1):
                    ans.append(matrix[row][end_col])
                end_col -= 1
            elif direction == 2: # right
                for col in range(end_col, start_col - 1, -1):
                    ans.append(matrix[end_row][col])
                end_row -= 1
            else: # up
                for row in range(end_row, start_row - 1, -1):
                    ans.append(matrix[row][start_col])
                start_col += 1
            direction = (direction + 1) % 4
        return ans