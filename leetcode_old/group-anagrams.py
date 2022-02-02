class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        table = dict()
        for s in strs:
            ss = "".join(sorted(s))
            if ss not in table:
                table[ss] = [s]
            else:
                table[ss].append(s)
        return list(table.values())
