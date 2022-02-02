class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ret = []
        target = set(target)
        for i in range(1, n+1):
            if len(target) == 0:
                break
            ret.append("Push")
            if i not in target:
                ret.append("Pop")
            else:
                target.remove(i)
        return ret
