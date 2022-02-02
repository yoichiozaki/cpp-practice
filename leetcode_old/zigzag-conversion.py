class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        interval = 2 * numRows - 2
        ret = ""
        for numRow in range(numRows):
            for i in range(numRow, len(s), interval):
                ret += s[i]
                if not (numRow == 0 or numRow == numRows - 1):
                    if i + interval - 2 * numRow < len(s):
                        ret += s[i + interval - 2 * numRow]
        return ret
