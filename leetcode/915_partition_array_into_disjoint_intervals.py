# Time: O(N), Space: O(N)
class Solution:
    def partitionDisjoint(self, A: List[int]) -> int:
        N = len(A)
        max_on_left = [None for _ in range(N)]
        max_on_left[0] = A[0]
        for i in range(1, N, 1):
            max_on_left[i] = max(max_on_left[i-1], A[i])

        min_on_right = [None for _ in range(N)]
        min_on_right[N-1] = A[N-1]
        for i in range(N-2, -1, -1):
            min_on_right[i] = min(min_on_right[i+1], A[i])

        for i in range(1, N, 1):
            if max_on_left[i-1] <= min_on_right[i]:
                return i

# Time: O(N), Space: O(N)


class Solution:
    def partitionDisjoint(self, A: List[int]) -> int:
        N = len(A)
        min_on_right = [None for _ in range(N)]
        min_on_right[N-1] = A[N-1]
        for i in range(N-2, -1, -1):
            min_on_right[i] = min(min_on_right[i+1], A[i])

        current_max = A[0]
        for i in range(1, N, 1):
            current_max = max(current_max, A[i-1])
            if current_max <= min_on_right[i]:
                return i

# Time: O(N), Space: O(1)


class Solution:
    def partitionDisjoint(self, A: List[int]) -> int:
        N = len(A)
        current_max = A[0]
        possible_max = A[0]
        length = 1
        for i in range(1, N, 1):
            if A[i] < current_max:
                length = i + 1  # 左側がA[:i+1]で一旦確定
                current_max = possible_max  # 左側最大値が確定
            else:
                possible_max = max(possible_max, A[i])
        return length
