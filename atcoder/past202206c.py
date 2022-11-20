N, M = map(int, input().split())
S = []
powered = 1
for i in range(1, M + 1):
    powered *= N
    if powered <= 10 ** 9:
        S.append("o")
    else:
        S += ["x" for _ in range(M - i + 1)]
        break
print("".join(S))