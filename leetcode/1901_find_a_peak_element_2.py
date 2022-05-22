# Time: O(H log W)
class Solution:
    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        left_col = 0
        right_col = len(mat[0]) - 1
        while left_col <= right_col:
            mid_col = (left_col + right_col) // 2
            
            highest_row = 0
            for row in range(len(mat)):
                highest_row = row if (mat[row][mid_col] >= mat[highest_row][mid_col]) else highest_row
            
            is_left_col_larger = left_col <= mid_col - 1 and mat[highest_row][mid_col - 1] > mat[highest_row][mid_col]
            is_right_col_larger = mid_col + 1 <= right_col and mat[highest_row][mid_col + 1] > mat[highest_row][mid_col]
            
            if not is_left_col_larger and not is_right_col_larger:
                return [highest_row, mid_col]
            elif is_left_col_larger:
                right_col = mid_col - 1
            else:
                left_col = mid_col + 1
                
        return []

# 考え方
# 縦か横方向のどちらか一方に二次元配列を一次元に「潰して」見ると、peakはその一次元配列の最大値のカラムの中にある
# 一次元に圧縮された状態でpeakを探すのは二分探索でできる。圧縮をまじめにやるとO(HW)かかってしまう
# 順番を逆にして、とりあえずcol内での頂を見つけてそれがrow方向に頂であるかを判定してrow方向の範囲を二分探索の要領で減らしていけばO(H log W)で計算できる
# 例：
# [
#  [4, 2, 5, 1, 4, 5],
#  [2, 9, 3, 2, 3, 2],
#  [1, 7, 6, 0, 1, 3],
#  [3, 6, 2, 3, 7, 2],
# ]
# これをcol方向に見ると
# [4, 9, 6, 3, 7, 5]
# 左から2番目のカラム内での最大値は二次元配列の中でのピークになっている。
# 左から1番目のカラム内の要素は左から1番目のカラムの最大値以下であって、左から3番目のカラム内の要素は左から3番目のカラムの最大値以下であるから左右方向については条件が満たされることがわかる
# 左から2番目のカラム内の値は、左から2番目のカラム内の値の最大値以下であるから上下方向についても条件を満たす
# ---
# 先に上下方向について条件を満たす位置を決めて、次に左右方向に条件を満たす位置を二分探索で探す