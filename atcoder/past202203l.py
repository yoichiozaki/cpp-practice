def f(x,a,m):
    if a==1:
        return 10 % M, x
    base, ret = f(x, a // 2, m)
    ret = (ret * base + ret) % m
    base = base * base % m
    if a % 2:
        ret = (ret * 10 + x) % m
        base = base * 10 % m
    return base, ret


K, M = map(int, input().split())
ans = 0
for i in range(K):
    c, d = map(int, input().split())
    base, ret = f(c, d, M)
    ans = (ans * base + ret) % M

print(ans)
