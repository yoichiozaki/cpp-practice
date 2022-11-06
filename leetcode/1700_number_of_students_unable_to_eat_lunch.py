# 先頭のサンドウィッチを食べたい人が出るまで学生を回す。先頭のサンドウィッチを食べたい学生が0になったタイミングで残っている学生はサンドウィッチを食べれない
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        cnt = Counter(students)
        N = len(students)
        k = 0
        while k < N and cnt[sandwiches[k]] != 0:
            cnt[sandwiches[k]] -= 1
            k += 1
        return N - k