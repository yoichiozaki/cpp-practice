class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        def distance(x, y):
            dist = 0
            for i in range(len(x)):
                if x[i] != y[i]:
                    dist += 1
            return dist
        
        ans = []
        for query in queries:
            if any(distance(query, item) <= 2 for item in dictionary):
                ans.append(query) 
        return ans