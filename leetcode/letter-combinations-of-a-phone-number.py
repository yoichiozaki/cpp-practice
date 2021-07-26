class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        ret = []
        if digits == "":
            return ret
        mapping = {
            2: ["a", "b", "c"],
            3: ["d", "e", "f"],
            4: ["g", "h", "i"],
            5: ["j", "k", "l"],
            6: ["m", "n", "o"],
            7: ["p", "q", "r", "s"],
            8: ["t", "u", "v"],
            9: ["w", "x", "y", "z"],
        }

        def rec(pos, sofar):
            if pos == len(digits):
                ret.extend(sofar)
                return
            next_sofar = []
            digit = int(digits[pos])
            for ch in mapping[digit]:
                for s in sofar:
                    next_sofar.append(s + ch)
            rec(pos + 1, next_sofar)
        rec(0, [""])
        return ret
