from collections import Counter
from itertools import permutations

s1 = input()
s2 = input()
s3 = input()

cnt = Counter(s1 + s2 + s3)
if 10 < len(cnt):
    print("UNSOLVABLE")
    exit()

perms = permutations([i for i in range(10)], len(cnt))
for perm in perms:
    s = list(set(s1 + s2 + s3))
    table = dict()
    for key, value in zip(s, perm):
        table[key] = value
    if table[s1[0]] == 0 or table[s2[0]] == 0 or table[s3[0]] == 0:
        continue

    def str_to_num(s):
        ret = 0
        for i, ch in enumerate(reversed(s)):
            ret += (10 ** i) * table[ch]
        return ret

    num1 = str_to_num(s1)
    num2 = str_to_num(s2)
    num3 = str_to_num(s3)

    if num1 + num2 == num3:
        print(num1, num2, num3, sep="\n")
        exit()
print("UNSOLVABLE")
