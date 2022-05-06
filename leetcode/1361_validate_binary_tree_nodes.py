class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        indegree = [0 for _ in range(n)]
        root = -1
        def helper(root):
            if root == -1:
                return 0
            return helper(leftChild[root]) + helper(rightChild[root]) + 1
        for i in range(n):
            if leftChild[i] != -1:
                if indegree[leftChild[i]] != 0:
                    return False # multiple parents
                else:
                    indegree[leftChild[i]] = 1
            if rightChild[i] != -1:
                if indegree[rightChild[i]] != 0:
                    return False # multiple parents
                else:
                    indegree[rightChild[i]] = 1
        for i in range(n):
            if indegree[i] == 0:
                if root == -1:
                    root = i
                else:
                    return False # multiple roots
        if root == -1:
            return False
        return helper(root) == n