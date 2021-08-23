class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        cnt = collections.Counter(arr)
        for ele in sorted(arr, key=abs):
            if cnt[ele] == 0:
                continue
            if cnt[ele * 2] == 0:
                return False
            cnt[ele] -= 1
            cnt[ele * 2] -= 1
        return True
