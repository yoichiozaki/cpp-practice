class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        uf = {ch: ch for ch in "abcdefghijklmnopqrstuvwxyz"}
        def find(ch):
            if uf[ch] != ch:
                uf[ch] = find(uf[ch])
            return uf[ch]
        for lhs, equality, _, rhs in equations:
            if equality == "=":
                uf[find(lhs)] = find(rhs)
        return not any(equality == "!" and find(lhs) == find(rhs) for lhs, equality, _, rhs in equations)