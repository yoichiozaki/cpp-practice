# min-heap
# matrix[i][j]の次に大きい要素はmatrix[i][j+1] or matrix[i+1][j]
# min-heapに候補となる値を全部突っ込みながらk番目を見つける
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        import heapq
        n = len(matrix)
        pq = []
        for col in range(n):
            heapq.heappush(pq, (matrix[0][col], 0, col))
        for _ in range(k - 1):
            (_, row, col) = heapq.heappop(pq)
            if row == n - 1:
                continue
            heapq.heappush(pq, (matrix[row + 1][col], row + 1, col))
        return pq[0][0]


# 二分探索
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        low = matrix[0][0]
        high = matrix[-1][-1] + 1
        while low < high:
            mid = (low + high) // 2
            cnt = 0
            j = len(matrix) - 1
            for i in range(len(matrix)):
                while 0 <= j and mid < matrix[i][j]:
                    j -= 1
                cnt += (j + 1)
            if cnt < k:
                low = mid + 1
            else:
                high = mid
        return low


# めぐる式二分探索
# 初めて「その値以下の数字がk個以上ある」を満たす値を二分探索
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        ng = matrix[0][0] - 1
        ok = matrix[-1][-1] + 1

        # 無駄の多い is_ok()
        # def is_ok(mid):
        #     cnt = 0
        #     for i in range(len(matrix)):
        #         for j in range(len(matrix[0])):
        #             if matrix[i][j] <= mid:
        #                 cnt += 1
        #             else:
        #                 break
        #     return k <= cnt

        # 改良版
        def is_ok(mid):
            cnt = 0
            j = len(matrix) - 1
            for i in range(len(matrix)):
                while 0 <= j and mid < matrix[i][j]:
                    j -= 1
                cnt += (j + 1)
            return k <= cnt

        while 1 < abs(ok - ng):
            mid = (ok + ng) // 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok
