"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None
        flatten_nodes = []
        def dfs(node):
            if node is None:
                return
            flatten_nodes.append(node)
            if node.child is not None:
                dfs(node.child)
            dfs(node.next)
        dfs(head)
        for i in range(len(flatten_nodes)):
            flatten_nodes[i].child = None
            if i == 0:
                flatten_nodes[i].prev = None
                flatten_nodes[i].next = flatten_nodes[i + 1]
            elif i == len(flatten_nodes) - 1:
                flatten_nodes[i].next = None
                flatten_nodes[i].prev = flatten_nodes[i - 1]
            else:
                flatten_nodes[i].prev = flatten_nodes[i - 1]
                flatten_nodes[i].next = flatten_nodes[i + 1]
        return flatten_nodes[0]