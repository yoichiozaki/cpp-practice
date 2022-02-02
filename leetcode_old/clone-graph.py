# DFS w/ stack
# # Definition for a Node.
# class Node:
#     def __init__(self, val = 0, neighbors = None):
#         self.val = val
#         self.neighbors = neighbors if neighbors is not None else []
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return node

        original_to_clone = dict()
        original_to_clone[node] = Node(val=node.val, neighbors=None)

        stack = [node]
        while len(stack) != 0:
            n = stack.pop()
            for neighbor in n.neighbors:
                if neighbor not in original_to_clone:
                    original_to_clone[neighbor] = Node(
                        val=neighbor.val, neighbors=None)
                    stack.append(neighbor)
                original_to_clone[n].neighbors.append(
                    original_to_clone[neighbor])

        return original_to_clone[node]


# BFS w/ queue
# # Definition for a Node.
# class Node:
#     def __init__(self, val = 0, neighbors = None):
#         self.val = val
#         self.neighbors = neighbors if neighbors is not None else []
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return node

        original_to_clone = dict()
        original_to_clone[node] = Node(val=node.val, neighbors=None)

        queue = collections.deque([node])
        while len(queue) != 0:
            n = queue.popleft()
            for neighbor in n.neighbors:
                if neighbor not in original_to_clone:
                    original_to_clone[neighbor] = Node(
                        val=neighbor.val, neighbors=None)
                    queue.append(neighbor)
                original_to_clone[n].neighbors.append(
                    original_to_clone[neighbor])

        return original_to_clone[node]


# DFS in recursion
# # Definition for a Node.
# class Node:
#     def __init__(self, val = 0, neighbors = None):
#         self.val = val
#         self.neighbors = neighbors if neighbors is not None else []
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return node

        clone = Node(val=node.val, neighbors=None)
        original_to_clone = {node: clone}

        def dfs(node):
            for neighbor in node.neighbors:
                if neighbor not in original_to_clone:
                    original_to_clone[neighbor] = Node(
                        val=neighbor.val, neighbors=None)
                    dfs(neighbor)
                original_to_clone[node].neighbors.append(
                    original_to_clone[neighbor])

        dfs(node)
        return original_to_clone[node]
