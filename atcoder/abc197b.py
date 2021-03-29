H, W, X, Y = map(int, input().split())
X -= 1
Y -= 1
field = [""] * H
for i in range(H):
    s = input()
    field[i] = s

has_visited = set()
dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

ans = 1

for (dh, dw) in dirs:
    suspended = [(X, Y)]
    while suspended:
        h_, w_ = suspended.pop()
        has_visited.add((h_, w_))
        if 0 <= h_ + dh < H and 0 <= w_ + dw < W and (h_ + dh, w_ + dw) not in has_visited and field[h_ + dh][w_ + dw] == ".":
            suspended.append((h_ + dh, w_ + dw))
            ans += 1

print(ans)
