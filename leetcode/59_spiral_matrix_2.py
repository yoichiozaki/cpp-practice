class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        result = [[0 for _ in range(n)] for _ in range(n)]
        counter = 1
        for layer in range(0, (n + 1) // 2, 1):
            
            # go right
            col = layer
            while col < n - layer:
                result[layer][col] = counter
                counter += 1
                col += 1
            
            # go down
            row = layer + 1
            while row < n - layer:
                result[row][n - layer - 1] = counter
                counter += 1
                row += 1
            
            # go left
            col = n - layer - 2
            while layer <= col:
                result[n - layer - 1][col] = counter
                counter += 1
                col -= 1
            
            # go up
            row = n - layer - 2
            while layer < row:
                result[row][layer] = counter
                counter += 1
                row -= 1
            
        return result


    class Solution:
        def generateMatrix(self, n: int) -> List[List[int]]:
            result = [[0 for _ in range(n)] for _ in range(n)]
            counter = 1
            dirs = [
                (0, 1),  # right
                (1, 0),  # down
                (0, -1), # left
                (-1, 0)  # up
            ]
            
            row = 0
            col = 0
            d = 0 # right
            
            while counter <= n * n:
                result[row][col] = counter
                counter += 1
                r = (((row + dirs[d][0]) % n) + n) % n
                c = (((col + dirs[d][1]) % n) + n) % n
                if result[r][c] != 0:
                    d = (d + 1) % 4
                row += dirs[d][0]
                col += dirs[d][1]
            
            return result