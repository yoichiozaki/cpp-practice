X, A, B, C = map(int, input().split())

if A * B * C + B * X < A * X:
    print("Hare")
elif A * B * C + B * X > A * X:
    print("Tortoise")
else:
    print("Tie")