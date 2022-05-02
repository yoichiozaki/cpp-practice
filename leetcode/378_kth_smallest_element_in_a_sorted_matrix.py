# binary search on 2d
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        low = matrix[0][0]
        high = matrix[-1][-1] + 1
        while low < high:
            mid = (low + high) // 2
            cnt = 0
            j = len(matrix[0]) - 1
            for i in range(len(matrix)):
                while 0 <= j and mid < matrix[i][j]:
                    j -= 1
                cnt += (j + 1)
            if cnt < k:
                low = mid + 1
            else:
                high = mid
        return low


# k番目に小さい要素はk個値を捨てた後のminheapの先頭。matrixが行・列のそれぞれの方向に整列しているので、matrix[i][j]の次に大きい要素はmatrix[i+1][j] or matrix[i][j+1]
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        import heapq
        n = len(matrix)
        heap = []
        for col in range(n):
            heapq.heappush(heap, (matrix[0][col], 0, col))
        for _ in range(k - 1):
            (_, row, col) = heapq.heappop(heap)
            if row == n - 1:
                continue
            heapq.heappush(heap, (matrix[row+1][col], row+1, col))
        return heap[0][0]