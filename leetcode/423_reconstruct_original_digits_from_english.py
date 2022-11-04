class Solution:
    def originalDigits(self, s: str) -> str:
        cnt = Counter(s)
        numbers_str = ["zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"]
        symbol_pos = [0, 2, 4, 6, 8, 1, 3, 5, 7, 9]
        cnt2 = [Counter(number_str) for number_str in numbers_str]
        found = [0]*10
        for pos, c in enumerate(cnt2):
            k = min(cnt[x] // c[x] for x in c)
            for i in c.keys():
                c[i] *= k
            cnt -= c
            found[symbol_pos[pos]] = k
            
        return "".join([str(i) * found[i] for i in range(10)])     