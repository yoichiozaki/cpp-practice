class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        def rotate_clockwise(mat):
            mat.reverse()
            for i in range(len(mat)):
                for j in range(i, len(mat)):
                    mat[i][j], mat[j][i] = mat[j][i], mat[i][j]
        def check(mat, target):
            for i in range(len(mat)):
                for j in range(len(mat)):
                    if mat[i][j] != target[i][j]:
                        return False
            return True
        for _ in range(4):
            rotate_clockwise(mat)
            if check(mat, target):
                return True
        return False