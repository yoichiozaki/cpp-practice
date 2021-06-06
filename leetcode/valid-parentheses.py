class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for p in s:
            if p in ["(", "{", "["]:
                stack.append(p)
                continue
            else:
                if len(stack) == 0:
                    return False
                q = stack.pop()
                if q in [")", "}", "]"]:
                    return False
                else:
                    if q+p in ["()", "{}", "[]"]:
                        continue
                    else:
                        stack.append(q)
                        stack.append(p)
        if len(stack) == 0:
            return True
        else:
            return False
