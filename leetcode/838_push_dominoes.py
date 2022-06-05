class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        symbols = [(-1, 'L')] + [(i, x) for i, x in enumerate(dominoes) if x != '.'] + [(len(dominoes), 'R')]
        ans = list(dominoes)
        for (i, x), (j, y) in zip(symbols, symbols[1:]):
            if x == y:
                for k in range(i + 1, j):
                    ans[k] = x
            elif x == 'R' and y == 'L':
                for k in range(i + 1, j):
                    if k - i > j - k:
                        ans[k] = 'L'
                    elif k - i < j - k:
                        ans[k] = 'R'
                    else: # k - i == j - k
                        ans[k] = '.'
            else: # x == 'L' and y == 'R'
                continue
        return "".join(ans)