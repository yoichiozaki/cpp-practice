class Solution:
    def maximumSwap(self, num: int) -> int:
        arr = list(str(num))
        ans = arr[:]
        for i in range(len(arr)):
            for j in range(i + 1, len(arr)):
                arr[i], arr[j] = arr[j], arr[i]
                if ans < arr:
                    ans = arr[:]
                arr[i], arr[j] = arr[j], arr[i]
        return int("".join(ans))
