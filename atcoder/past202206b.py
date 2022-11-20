S = input()
memo = dict()
for i in range(len(S) - 1):
    if S[i:i + 2] not in memo:
        memo[S[i:i + 2]] = 1
    else:
        memo[S[i:i + 2]] += 1
lst = [(-cnt, s) for (s, cnt) in memo.items()]
lst.sort()
print(lst[0][1])