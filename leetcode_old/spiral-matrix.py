# Simulation
# Time: O(R * C), Additional Space: O(R * C)
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        R = len(matrix)
        C = len(matrix[0])
        dirs = [
            (0,  1),  # right
            (1,  0),  # down
            (0, -1),  # left
            (-1, 0),  # up
        ]
        has_visited = [[False for _ in range(C)] for _ in range(R)]

        ans = list()

        current_r = 0
        current_c = 0
        current_dir = 0
        for _ in range(R * C):
            ans.append(matrix[current_r][current_c])
            has_visited[current_r][current_c] = True
            next_r = current_r + dirs[current_dir][0]
            next_c = current_c + dirs[current_dir][1]
            if 0 <= next_r < R and 0 <= next_c < C and not has_visited[next_r][next_c]:
                current_r = next_r
                current_c = next_c
            else:
                current_dir = (current_dir + 1) % 4
                current_r += dirs[current_dir][0]
                current_c += dirs[current_dir][1]
        return ans


# Layer by layer: 外側から1段ずつめくる
# Time: O(R * C), Additional Space: O(1)
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        def _coords_by_layer(r0, c0, r1, c1):
            for c in range(c0, c1 + 1, 1):
                yield r0, c
            for r in range(r0 + 1, r1 + 1, 1):
                yield r, c1
            if r0 < r1 and c0 < c1:
                for c in range(c1 - 1, c0, -1):
                    yield r1, c
                for r in range(r1, r0, -1):
                    yield r, c0

        ans = []
        if len(matrix) == 0:
            return ans

        r0 = 0
        c0 = 0

        r1 = len(matrix) - 1
        c1 = len(matrix[0]) - 1

        while r0 <= r1 and c0 <= c1:
            for r, c in _coords_by_layer(r0, c0, r1, c1):
                ans.append(matrix[r][c])
            r0 += 1
            r1 -= 1
            c0 += 1
            c1 -= 1
        return ans
