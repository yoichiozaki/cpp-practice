class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def splitBST(root, v):
    inordered = []

    def inorder_traverse(root):
        if root is None:
            return
        inorder_traverse(root.left)
        inordered.append(root.val)
        inorder_traverse(root.right)
    inorder_traverse(root)
    idx = inordered.index(v)

    def build_bst(i, j):
        if j < i:
            return None
        mid = (i + j) // 2
        root = TreeNode(inordered[mid])
        root.left = build_bst(i, mid-1)
        root.right = build_bst(mid+1, j)
        return root
    return [build_bst(0, idx), build(idx, len(inordered)-1)]
