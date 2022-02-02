# in-placeじゃない回転は「回転後の行列」を主語に考えるとわかりやすい
# https://zakimal.github.io/ja/post/rotate-2d-array/

# まじめ
# 縦長の長方形を傾ける
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        for i in range(n // 2 + n % 2):
            for j in range(n // 2):
                tmp = matrix[n - 1 - j][i]
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1]
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i]
                matrix[j][n - 1 - i] = matrix[i][j]
                matrix[i][j] = tmp


# ちょっとトリック
# 対角成分ひっくり返したあとに左右反転
# 左右反転したあとに対角成分ひっくり返すと左90°回転
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        def transpose(matrix):
            n = len(matrix)
            for i in range(n):
                for j in range(i, n):
                    matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        def reflect(matrix):
            n = len(matrix)
            for i in range(n):
                for j in range(n // 2):
                    matrix[i][j], matrix[i][-j -
                                            1] = matrix[i][-j-1], matrix[i][j]

        transpose(matrix)
        reflect(matrix)
