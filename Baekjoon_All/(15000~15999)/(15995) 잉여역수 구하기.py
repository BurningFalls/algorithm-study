a, m = map(int, input().split())
for i in range(m):
    if (m * i + 1) % a == 0:
        print((m * i + 1) // a)
        break