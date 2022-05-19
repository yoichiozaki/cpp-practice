class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        # バブルソートみたいに最大要素から順番に正しい位置に持っていく
        # 位置未確定の要素までを含む部分配列を反転すれば、かならず位置未確定要素が先頭に来るので未確定要素たちをもう一度ひっくり返せば位置未確定要素を配列末尾に持っていくことができる
        def flip(lst, length):
            i = 0
            while i < length // 2:
                lst[i], lst[length - i - 1] = lst[length - i - 1], lst[i]
                i += 1
        ans = []
        target = len(arr)
        while 0 < target:
            idx = arr.index(target)
            if idx != target - 1: # しかるべき位置にしかるべき値がないのでひっくり返す
                if idx != 0:
                    ans.append(idx + 1)
                    flip(arr, idx + 1)
                ans.append(target)
                flip(arr, target)
            target -= 1
        return ans