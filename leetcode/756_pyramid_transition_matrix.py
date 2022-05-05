class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        if len(allowed) == 0:
            return False
        invalid = set()
        def dfs(cur, pos, nxt):
            if len(cur) == 1:
                return True
            if cur in invalid:
                return False
            if pos == len(cur) - 1:
                return dfs(nxt, 0, "")
            for allow in allowed:
                if allow[:2] == cur[pos:pos+2]:
                    if dfs(cur, pos + 1, nxt + allow[-1]):
                        return True
            invalid.add(cur)
            return False
        return dfs(bottom, 0, "")