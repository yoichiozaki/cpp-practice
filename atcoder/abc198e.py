N = int(input())
C = list(map(int, input().split()))

G = [[]for _ in range(N)]
for i in range(N - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)

is_good = [False] * 101010
cnt = [0] * 101010


def dfs(n, parent=-1):
    if cnt[C[n]] == 0:
        is_good[n] = True
    cnt[C[n]] += 1
    for v in G[n]:
        if v != parent:
            dfs(v, n)
    cnt[C[n]] -= 1


dfs(0)
for i in range(N):
    if is_good[i]:
        print(i + 1)
